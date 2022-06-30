#include "utility.h"
#include "monopoly.h"
#include <QDebug>

Utility::Utility(int space_num, const QString& name, int price)
    : PropertySpace(space_num, name, price) {}

void Utility::playerOn(Player *player)
{
    Monopoly::instance()->enableButtons();
    qDebug() << "a player on utility";
}
