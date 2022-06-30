#include "station.h"
#include "deed.h"
#include "monopoly.h"
#include <QTimer>
#include <QDebug>

Station::Station(int space_num, const QString& name, int price, int rent, int two_station, int three_station, int four_station, int mortgage)
                : PropertySpace(space_num, name, price), RENT(rent), TWO_STATION(two_station),
                  THREE_STATINO(three_station), FOUR_STATION(four_station), MORTGAGE(mortgage) {}

void Station::playerOn(Player *player)
{
    Monopoly::instance()->enableButtons();
    qDebug() << "a player on station";
}
