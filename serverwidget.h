#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QMainWindow>
#include <QTcpServer> //监听套接字
#include <QTcpSocket> //通信套接字
namespace Ui {
class ServerWidget;
}

class ServerWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerWidget(QWidget *parent = 0);
    ~ServerWidget();

private slots:
    void on_buttonSend_clicked();

    void on_buttonClose_clicked();

private:
    Ui::ServerWidget *ui;

    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;

};

#endif // SERVERWIDGET_H
