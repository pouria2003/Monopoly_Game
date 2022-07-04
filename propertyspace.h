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
    PropertySpace(int space_num, const QString& name, int price);
    virtual int rent() = 0;

public:
    Player *owner;
    DeedContainer *t;
    const QString NAME;
    const int PRICE;
    int level;

};

#endif // PROPERTYSPACE_H
