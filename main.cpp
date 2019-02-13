#include "serverwidget.h"
#include "clientwidge.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ServerWidget w;
    w.show();
    ClientWidge w2;
    w2.show();

    return a.exec();
}
