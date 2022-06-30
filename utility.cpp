#include "utility.h"
#include <QDebug>

Utility::Utility(int space_num, const QString& name, int price)
    : PropertySpace(space_num, name, price) {}

void Utility::playerOn(Player *player)
{
    qDebug() << "a player on utility";
}
