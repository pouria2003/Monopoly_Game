#ifndef UTILITY_H
#define UTILITY_H

#include "propertyspace.h"

class Utility : public PropertySpace
{
public:
    Utility(int space_num, const QString & name, int price);
    void playerOn(Player *) override;
    int rent() override;

};

#endif // UTILITY_H
