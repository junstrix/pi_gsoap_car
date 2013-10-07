#include "widget.h"
#include "ui_widget.h"
#include "soappiProxy.h"
#include "pi.nsmap"

piProxy client; // create object
int result = 0; // return back value
int motor_dir = 0;
char serveripaddr[128] = "192.168.1.118:8888";
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_start_pushButton_clicked()
{
    const char *tmp_str = ui->server_lineEdit->text().toStdString().c_str();
    strcpy(serveripaddr,tmp_str);
    ui->server_lineEdit->setEnabled(false);
    ui->start_pushButton->setText("Stop");
}

void Widget::on_stop_pushButton_clicked()
{
    motor_dir = 0;
    client.soap_endpoint = serveripaddr;
    client.motor_con(motor_dir,&result);
}

void Widget::on_forward_pushButton_clicked()
{
    motor_dir = 1;
    client.soap_endpoint = serveripaddr;
    client.motor_con(motor_dir,&result);
}

void Widget::on_back_pushButton_clicked()
{
    motor_dir = 2;
    client.soap_endpoint = serveripaddr;
    client.motor_con(motor_dir,&result);
}

void Widget::on_left1_pushButton_clicked()
{
    motor_dir = 3;
    client.soap_endpoint = serveripaddr;
    client.motor_con(motor_dir,&result);
}

void Widget::on_right1_pushButton_clicked()
{
    motor_dir = 4;
    client.soap_endpoint = serveripaddr;
    client.motor_con(motor_dir,&result);
}

void Widget::on_left2_pushButton_clicked()
{
    motor_dir = 5;
    client.soap_endpoint = serveripaddr;
    client.motor_con(motor_dir,&result);
}

void Widget::on_right2_pushButton_clicked()
{
    motor_dir = 6;
    client.soap_endpoint = serveripaddr;
    client.motor_con(motor_dir,&result);
}
