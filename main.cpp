#include "mainwindow.h"
#include <QApplication>
#include "street.h"
#include "player.h"


/// override close so can send enable slot when a deed close
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
