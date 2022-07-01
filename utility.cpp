#include "utility.h"
#include "monopoly.h"
#include <QDebug>

Utility::Utility(int space_num, const QString& name, int price)
    : PropertySpace(space_num, name, price) {}

void Utility::playerOn(Player *player)
{
    Monopoly::instance()->enableButtons();
    Monopoly::instance()->space_done();
}

int Utility::rent()
{
    return 0;
}
