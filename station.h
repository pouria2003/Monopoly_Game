#ifndef STATION_H
#define STATION_H

#include "propertyspace.h"
#include <QString>


class Station : public PropertySpace
{
public:
    Station(int space_num, const QString& name, int price, int rent, int two_station, int three_station, int four_station, int mortgage);
    void playerOn(Player *) override;


public:
    const int RENT;
    const int TWO_STATION;
    const int THREE_STATINO;
    const int FOUR_STATION;
    const int MORTGAGE;


};

#endif // STATION_H
