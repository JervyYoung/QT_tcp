#include "clientwidge.h"
#include "ui_clientwidge.h"
#include <QHostAddress>

ClientWidge::ClientWidge(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidge)
{
    ui->setupUi(this);
    setWindowTitle("Client");
    tcpSocket=NULL;
    tcpSocket=new QTcpSocket(this);
    connect(tcpSocket,&QTcpSocket::connected,[=](){
        ui->textEdit->setText("connect success");
    });

    connect(tcpSocket,&QTcpSocket::readyRead,[=](){

        QByteArray array=tcpSocket->readAll();
        ui->textEdit->append(array);
    });

}

ClientWidge::~ClientWidge()
{
    delete ui;
}

void ClientWidge::on_pushButtonConnect_clicked()
{
    //获取服务器ip和端口
    QString ip=ui->lineEditIp->text();
    qint16 port=ui->lineEditPort->text().toInt();

    tcpSocket->connectToHost(QHostAddress(ip),port);

}

void ClientWidge::on_pushButtonSend_clicked()
{
    QString str=ui->textEdit_2->toPlainText();

    tcpSocket->write(str.toUtf8().data());
}

void ClientWidge::on_pushButton_3_clicked()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}
