#ifndef PROPERTYSPACE_H
#define PROPERTYSPACE_H

#include "boardspace.h"
#include <QString>

class DeedContainer;
class Player;
class Deed;

class PropertySpace : public BoardSpace
{
public:
    PropertySpace(int space_num, const QString& name, int price, int mortgage);
    virtual int rent() = 0;

public:
    Player *owner;
    DeedContainer *t;
    const QString NAME;
    const int PRICE;
    const int MORTGAGE;
    int level;
    bool in_mortgage;

};

#endif // PROPERTYSPACE_H
