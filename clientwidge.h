#ifndef CLIENTWIDGE_H
#define CLIENTWIDGE_H

#include <QWidget>
#include <QTcpSocket>
namespace Ui {
class ClientWidge;
}

class ClientWidge : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidge(QWidget *parent = 0);
    ~ClientWidge();

private slots:
    void on_pushButtonConnect_clicked();

    void on_pushButtonSend_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ClientWidge *ui;
    QTcpSocket *tcpSocket;
};

#endif // CLIENTWIDGE_H
