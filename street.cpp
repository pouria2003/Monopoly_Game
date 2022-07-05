#include "street.h"
#include "deed.h"
#include "monopoly.h"
#include "deedcontainer.h"
#include "player.h"

Street::Street(int space_num, StreetColor _color, const QString& name, int price, int rent, int with_one_house, int with_two_house,
               int with_three_house, int with_four_house, int with_hotel, int construction, int mortgage)

    : PropertySpace(space_num, name, price, mortgage), RENT(rent), WITH_ONE_HOUSE(with_one_house),
      WITH_TWO_HOUSE(with_two_house), WITH_THREE_HOUSE(with_three_house), WITH_FOUR_HOUSE(with_four_house),
      WITH_HOTEL(with_hotel), CONSTRUCTION(construction), color(_color)
{
    buff = new char[sizeof (DeedContainer)];
    t = nullptr;
    level = 0;
}

StreetColor Street::getColor()
{
    return this->color;
}

void Street::playerOn(Player *player)
{

    if(owner == nullptr) {
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

int Street::rent()
{
    if(in_mortgage)
        return 0;
    switch (level) {
    case 0: return (is_grouped) ?  2 * RENT : RENT;
    case 1: return WITH_ONE_HOUSE;
    case 2: return WITH_TWO_HOUSE;
    case 3: return WITH_THREE_HOUSE;
    case 4: return WITH_FOUR_HOUSE;
    case 5: return WITH_HOTEL;
    default: return RENT;

    }
}
