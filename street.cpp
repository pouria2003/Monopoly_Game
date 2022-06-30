#include "street.h"
#include "deed.h"
#include "monopoly.h"
#include "deedcontainer.h"

Street::Street(int space_num, StreetColor _color, const QString& name, int price, int rent, int with_one_house, int with_two_house,
               int with_three_house, int with_four_house, int with_hotel, int construction, int mortgage)

    : PropertySpace(space_num, name, price), RENT(rent), WITH_ONE_HOUSE(with_one_house),
      WITH_TWO_HOUSE(with_two_house), WITH_THREE_HOUSE(with_three_house), WITH_FOUR_HOUSE(with_four_house),
      WITH_HOTEL(with_hotel), CONSTRUCTION(construction), MORTGAGE(mortgage), color(_color)
{
}

StreetColor Street::getColor()
{
    return this->color;
}

void Street::playerOn(Player *player)
{
    qDebug() << "1";
    t = new DeedContainer(this);
    qDebug() << "2";

    if(owner == nullptr) {
        qDebug() << "in player on fun street";
        t->Mshow(player);
    }
    else {
        Monopoly::instance()->getRent(this);
    }
    qDebug() << "3";
}
