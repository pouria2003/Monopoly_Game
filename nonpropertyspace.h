#ifndef NONPROPERTYSPACE_H
#define NONPROPERTYSPACE_H

#include "boardspace.h"

class Player;

enum NonPropertySpaceKind {
    Jail = 0, GoToJail, Go, FreeParking,
    Chest, Chance, IncomeTax, SuperTax
};

class NonPropertySpace : public BoardSpace
{
public:
    NonPropertySpace(int space_num, NonPropertySpaceKind);
    NonPropertySpaceKind getSpaceKind();
    void playerOn(Player *) override;

private:
    NonPropertySpaceKind space_kind;
    int number;
};

#endif // NONPROPERTYSPACE_H
