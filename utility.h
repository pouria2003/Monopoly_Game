#ifndef UTILITY_H
#define UTILITY_H

#include "propertyspace.h"

class Utility : public PropertySpace
{
public:
    Utility(int space_num, const QString & name, int price, int mortgage);
    void playerOn(Player *) override;
    int rent() override;

public:
    bool owned_boath;
    const int MORTGAGE;

};

#endif // UTILITY_H
