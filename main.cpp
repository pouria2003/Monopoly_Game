#include "mainwindow.h"
#include <QApplication>
#include "station.h"
#include "player.h"
#include "paidrent.h"
#include "deedcontainer.h"
#include "paidrentcontainer.h"
#include "auction.h"
#include "auctioncontainer.h"
#include "street.h"
#include "build.h"
#include "buildcontainer.h"
#include "chance_chest_container.h"
#include "sellcontainer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

//    QVector<int> * s = new QVector<int>;
//    s->push_back(1);
//    s->push_back(3);

//    SellContainer *sc = new SellContainer();
//    sc->createSell(s);

    return a.exec();
}
