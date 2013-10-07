#include "soapH.h"
#include "pi.nsmap"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>


#define handle_error(msg)\
	do {perror(msg); exit(EXIT_FAILURE);} while(0)
#define BACKLOG (100) // Max. request backlog
#define MAX_THR (10) // Max. threads to serve requests

void gpio_init()
{
	system("/usr/local/bin/gpio -g mode 22 out");
	system("/usr/local/bin/gpio -g mode 23 out");
	system("/usr/local/bin/gpio -g mode 24 out");
	system("/usr/local/bin/gpio -g mode 25 out");
}
void motor_dir(int dir)
{
//	IN1	IN2	IN3	IN4	电机
//      23	22	24	25	GPIO
//	0	0	0	0	停止
//	0	1	1	0	前进
//	1	0	0	1	后退
//	0	0	1	0	左前转弯
//	0	1	0	0	右前转弯
//	0	0	0	1	左后转弯
//	1	0	0	0	右后转弯
	
	switch (dir)
	{
		case 0 : // 停止
			system("/usr/local/bin/gpio -g write 22 0");
			system("/usr/local/bin/gpio -g write 23 0");
			system("/usr/local/bin/gpio -g write 24 0");
			system("/usr/local/bin/gpio -g write 25 0");
			break;
		case 1 : // 前进
			motor_dir(0);
			system("/usr/local/bin/gpio -g write 22 1");
			system("/usr/local/bin/gpio -g write 24 1");
			break;
		case 2 : // 后退
			motor_dir(0);
			system("/usr/local/bin/gpio -g write 23 1");
			system("/usr/local/bin/gpio -g write 25 1");
			break;
		case 3 : // 左前转弯
			motor_dir(0);
			system("/usr/local/bin/gpio -g write 23 1");
			break;
		case 4 : // 右前转弯
			motor_dir(0);
			system("/usr/local/bin/gpio -g write 22 1");
			break;
		case 5 : // 左后转弯
			motor_dir(0);
			system("/usr/local/bin/gpio -g write 25 1");
			break;
		case 6 : // 右后转弯
			motor_dir(0);
			system("/usr/local/bin/gpio -g write 23 1");
			break;
		default : break;
	}
}
int pi__motor_con(struct soap *soap, int dir, int *result)
{
	switch (dir)
	{
		case 0 : motor_dir(0); break; // 停止
		case 1 : motor_dir(1); break; // 前进
		case 2 : motor_dir(2); break; // 后退
		case 3 : motor_dir(3); break;
		case 4 : motor_dir(4); break;
		case 5 : motor_dir(5); break;
		case 6 : motor_dir(6); break;
		default : break;
	}
	return *result = 0;
}
int http_get(struct soap * soap)
{
	FILE *fd = NULL;
	char *s = strchr(soap->path, '?');
	if (!s || strcmp(s, "?wsdl"))
		return SOAP_GET_METHOD;
	fd = fopen("pi.wsdl", "rb");
	if (!fd)
		return 404;
	soap->http_content = "text/xml";
	soap_response(soap, SOAP_FILE);
	for (;;)
	{
		size_t r = fread(soap->tmpbuf, 1, sizeof(soap->tmpbuf), fd);
		if (!r)
			break;
		if (soap_send_raw(soap, soap->tmpbuf, r))
			break;
	}
	fclose(fd);
	soap_end_send(soap);
	return SOAP_OK;
}

int main(int argc, char **argv)
{
	daemon(1,0);
	gpio_init();
	int master_socket,slave_socket;
	struct soap soap;
	int i;
	struct soap *soap_thr[MAX_THR]; // each thread needs a runtime context
	pthread_t tid[MAX_THR];
	if (argc < 2) {
		fprintf(stderr, "usage: %s <server_port> \n", argv[0]);
		exit(EXIT_FAILURE);
	}
	soap_init(&soap); //初始化soap
	soap.fget = http_get;
	master_socket = soap_bind(&soap, NULL, atoi(argv[1]), BACKLOG);
	if (!soap_valid_socket(master_socket))
		exit(EXIT_FAILURE);
	fprintf(stderr, "Socket connection successful %d\n", master_socket);
	for (i = 0; i < MAX_THR; i++)
		soap_thr[i] = NULL;
	while(1) {
		for ( i = 0; i < MAX_THR; i++)
		{
			slave_socket = soap_accept(&soap);
			if (!soap_valid_socket(slave_socket))
			{
				if (soap.errnum)
				{
					soap_print_fault(&soap,stderr);
					continue; // retry
				}
				else {
					fprintf(stderr,"Server timed out\n");
					break;
				}
			}
			fprintf(stderr, "Thread %d accepts socket %d connection from IP %d.%d.%d.%d\n", \
					i, slave_socket, (soap.ip >> 24)&0xFF, (soap.ip >> 16)&0xFF, (soap.ip >> 8)&0xFF,
					soap.ip&0xFF);
			if (!soap_thr[i]) // first time around
			{
				soap_thr[i] = soap_copy(&soap);
				if (!soap_thr[i])
					exit(EXIT_FAILURE); // could not allocate
			}
			else// recycle soap context
			{
				pthread_join(tid[i], NULL);
				fprintf(stderr, "Thread %d completed\n", i);
				soap_destroy(soap_thr[i]); // deallocate C++ data of old thread
				soap_end(soap_thr[i]); // deallocate data of old thread
			}
			soap_thr[i]->socket = slave_socket; // new socket fd
			pthread_create(&tid[i], NULL, (void*(*)(void*))soap_serve, (void*)soap_thr[i]);
		}
	}
	for (i = 0; i < MAX_THR; i++)
		if (soap_thr[i])
		{
			soap_done(soap_thr[i]); // detach context
			free(soap_thr[i]); // free up
		}
	return 0;
}
