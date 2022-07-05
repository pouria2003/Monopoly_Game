#include "station.h"
#include "deed.h"
#include "monopoly.h"
#include "deedcontainer.h"
#include <QTimer>
#include <QDebug>

Station::Station(int space_num, const QString& name, int price, int rent, int two_station, int three_station, int four_station, int mortgage)
                : PropertySpace(space_num, name, price, mortgage), RENT(rent), TWO_STATION(two_station),
                  THREE_STATION(three_station), FOUR_STATION(four_station)
{
    buff = new char[sizeof(DeedContainer)];
    t = nullptr;
    stations_number = 0;
}

void Station::playerOn(Player *player)
{
//    static bool is_des = true;

//    if(t != nullptr && !is_des) {
//        t->~DeedContainer();
//        is_des = true;
//    }

    if(owner == nullptr) {
//        t = new(buff) DeedContainer(this, Monopoly::instance());
//        is_des = false;
//        t->Mshow(player);
        Monopoly::instance()->showBuyDeed(player, this);
    }
    else if (player != owner) {
        Monopoly::instance()->getRent(player, owner, this->rent());
        Monopoly::instance()->space_done();
    }
    else {
        Monopoly::instance()->space_done();
    }
}

int Station::rent()
{
    if(in_mortgage)
        return 0;
    switch (stations_number) {
    case 1: return RENT;
    case 2: return TWO_STATION;
    case 3: return THREE_STATION;
    case 4: return FOUR_STATION;
    default: return RENT;
    }
}
