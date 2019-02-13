#include "serverwidget.h"
#include "ui_serverwidget.h"

ServerWidget::ServerWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    tcpServer=NULL;
    tcpSocket=NULL;
    tcpServer=new QTcpServer(this);

    tcpServer->listen(QHostAddress::Any,8888);

    setWindowTitle("server 8888");
    connect(tcpServer,&QTcpServer::newConnection,[=]()
    {
        //取出建立好链接的套接字
        tcpSocket=tcpServer->nextPendingConnection();
        //获取对方ip和端口
        QString ip=tcpSocket->peerAddress().toString();
        qint16 port=tcpSocket->peerPort();
        QString temp=QString("[%1:%2]:成功链接").arg(ip).arg(port);
        ui->textEditRead->setText(temp);

        connect(tcpSocket,&QTcpSocket::readyRead,
                [=](){
            QByteArray array= tcpSocket->readAll();
            ui->textEditRead->append(array);
        });
    });


}

ServerWidget::~ServerWidget()
{
    delete ui;
}

void ServerWidget::on_buttonSend_clicked()
{
    if(NULL==tcpSocket)
    {
        return;
    }
    QString str=ui->textEditWrite->toPlainText();

    tcpSocket->write(str.toUtf8().data());
}

void ServerWidget::on_buttonClose_clicked()
{
    if(NULL==tcpSocket)
    {
        return;
    }
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket=NULL;
}
