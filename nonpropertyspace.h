#ifndef NONPROPERTYSPACE_H
#define NONPROPERTYSPACE_H

#include "boardspace.h"

class Player;

enum NonPropertySpaceKind {
    Jail, GoToJail, Go, FreeParking,
    Chest, IncomeTax, Chance, SuperTax
};

class NonPropertySpace : public BoardSpace
{
public:
    NonPropertySpace(int space_num, NonPropertySpaceKind);
    NonPropertySpaceKind getSpaceKind();
    void playerOn(Player *) override;

private:
    NonPropertySpaceKind space_kind;
};

#endif // NONPROPERTYSPACE_H
