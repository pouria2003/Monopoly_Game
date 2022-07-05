#include "utility.h"
#include "monopoly.h"
#include <QDebug>

Utility::Utility(int space_num, const QString& name, int price, int mortgage)
    : PropertySpace(space_num, name, price, mortgage) {}

void Utility::playerOn(Player *player)
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
    }}

int Utility::rent()
{
    if(in_mortgage)
        return 0;
    int dices_num = Monopoly::instance()->dices_num();
    return ( (owned_boath) ? 4 * dices_num : 10 * dices_num );
}
