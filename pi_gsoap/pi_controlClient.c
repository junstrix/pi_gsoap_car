#include "soapStub.h"
#include "pi.nsmap"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
	int motor_dir = atoi(argv[2]);
	char server[128] = {0};
	struct soap add_soap;
	int result = 0;
	if (argc < 3) {
		printf("usage: %s <ip:port> motor_op\n", argv[0]);
		exit(1);
	}
	strcpy(server,argv[1]);
	soap_init(&add_soap);
	soap_set_namespaces(&add_soap, namespaces);
	soap_call_pi__motor_con(&add_soap,server,NULL,motor_dir,&result);
	if (add_soap.error)
	{
		printf("soap error: %d, %s, %s\n", add_soap.error,
				*soap_faultcode(&add_soap), *soap_faultstring(&add_soap));
		result = add_soap.error;
	}
	soap_end(&add_soap);
	soap_done(&add_soap);
	return 0;
}
