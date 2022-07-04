#ifndef STREET_H
#define STREET_H

#include "propertyspace.h"
#include <QString>

enum StreetColor {
    SC_PINK, SC_GREEN, SC_BLUE, SC_LIGHTBLUE,
    SC_RED, SC_BROWN, SC_ORANGE, SC_YELLOW
};


class Street : public PropertySpace
{
public:
    Street(int space_num, StreetColor _color, const QString& name, int price, int rent, int with_one_house, int with_two_house,
           int with_three_house, int with_four_house, int with_hotel, int construction, int mortgage);
    StreetColor getColor();
    void playerOn(Player *) override;
    int rent() override;

public:
    const int RENT;
    const int WITH_ONE_HOUSE;
    const int WITH_TWO_HOUSE;
    const int WITH_THREE_HOUSE;
    const int WITH_FOUR_HOUSE;
    const int WITH_HOTEL;
    const int CONSTRUCTION;
    const int MORTGAGE;
    char *buff;
    bool is_grouped;


private:
    StreetColor color;
};

#endif // STREET_H
