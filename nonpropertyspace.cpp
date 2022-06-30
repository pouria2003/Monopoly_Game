#include "nonpropertyspace.h"
#include <QDebug>

NonPropertySpace::NonPropertySpace(int space_num, NonPropertySpaceKind _space_kind)
    : BoardSpace(space_num), space_kind(_space_kind)
{

}

NonPropertySpaceKind NonPropertySpace::getSpaceKind() {
    return space_kind;
}

void NonPropertySpace::playerOn(Player *player)
{
    qDebug() << "a player on non property space";
}
