#include "nonpropertyspace.h"
#include "monopoly.h"
#include <QRandomGenerator>
#include "player.h"

#include <QDebug>

NonPropertySpace::NonPropertySpace(int space_num, NonPropertySpaceKind _space_kind)
    : BoardSpace(space_num), space_kind(_space_kind)
{
    if(space_kind == NonPropertySpaceKind::Chance || space_kind == NonPropertySpaceKind::Chest)
        number = QRandomGenerator::global()->bounded(1, 9);
}

NonPropertySpaceKind NonPropertySpace::getSpaceKind() {
    return space_kind;
}

void NonPropertySpace::playerOn(Player *player)
{
    number %= 8;
    ++number;
    switch (space_kind) {
    case GoToJail: player->goToJail(); break;
    case Chance: Monopoly::instance()->showChance(Chance, number); break;
    case Chest:  Monopoly::instance()->showChance(Chest, number); break;
    case IncomeTax: Monopoly::instance()->getIncomTax(); Monopoly::instance()->space_done(); break;
    case SuperTax: Monopoly::instance()->getSuperTax(); Monopoly::instance()->space_done(); break;
    default :    Monopoly::instance()->space_done();

    }
}
