#include "propertyspace.h"

PropertySpace::PropertySpace(int space_num, const QString &name, int price, int mortgage)
    : BoardSpace(space_num), NAME(name), PRICE(price), MORTGAGE(mortgage)
{
    owner = nullptr;
    in_mortgage = false;
}

