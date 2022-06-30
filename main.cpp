#include "mainwindow.h"
#include <QApplication>
#include "street.h"
#include "player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MainWindow w;
//    w.show();

    Player *pl = new Player("pouria", PlayerColor::BLUE);

    PropertySpace *p = new Street(0, SC_BLUE, ("خاقانی"), 1, 1, 1, 1, 1, 1, 1, 1, 1);
    qDebug() << "main 1";
    p->playerOn(pl);


    return a.exec();
}
