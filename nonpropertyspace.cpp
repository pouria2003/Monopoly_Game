#include "nonpropertyspace.h"
#include "monopoly.h"

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
    Monopoly::instance()->enableButtons();
    qDebug() << "a player on non property space";
}
