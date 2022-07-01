#include "mainwindow.h"
#include <QApplication>
#include "station.h"
#include "player.h"
#include "deedcontainer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
