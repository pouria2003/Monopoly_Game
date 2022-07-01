#include "street.h"
#include "deed.h"
#include "monopoly.h"
#include "deedcontainer.h"
#include "player.h"

Street::Street(int space_num, StreetColor _color, const QString& name, int price, int rent, int with_one_house, int with_two_house,
               int with_three_house, int with_four_house, int with_hotel, int construction, int mortgage)

    : PropertySpace(space_num, name, price), RENT(rent), WITH_ONE_HOUSE(with_one_house),
      WITH_TWO_HOUSE(with_two_house), WITH_THREE_HOUSE(with_three_house), WITH_FOUR_HOUSE(with_four_house),
      WITH_HOTEL(with_hotel), CONSTRUCTION(construction), MORTGAGE(mortgage), color(_color)
{
    buff = new char[sizeof (DeedContainer)];
    t = nullptr;
    house_number = 0;
}

StreetColor Street::getColor()
{
    return this->color;
}

void Street::playerOn(Player *player)
{

    static bool is_des = true;

    qDebug() << "mikham beram to if _ is_des hast " << is_des;
    if(t != nullptr && !is_des) {
        qDebug() << "raftam to if is_des hast " << is_des;
        t->~DeedContainer();
        is_des = true;
        qDebug() << "is des shod " << is_des;

    }

    if(owner == nullptr) {


        t = new(buff) DeedContainer(this, Monopoly::instance());
        is_des = false;
        qDebug() << "is des shod " << is_des;

        t->Mshow(player);

    }
    else if (player != owner) {

        Monopoly::instance()->getRent(player, this->rent());
        Monopoly::instance()->space_done();

    }
}

int Street::rent()
{
    qDebug() << "in rent 1";

    switch (house_number) {
    case 0: return RENT;
    case 1: return WITH_ONE_HOUSE;
    case 2: return WITH_TWO_HOUSE;
    case 3: return WITH_THREE_HOUSE;
    case 4: return WITH_FOUR_HOUSE;
    case 5: return WITH_HOTEL;
    default: return RENT;
   qDebug() << "in rent  1";

    }
}
