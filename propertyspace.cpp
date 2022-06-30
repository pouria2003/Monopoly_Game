#include "propertyspace.h"

PropertySpace::PropertySpace(int space_num, const QString &name, int price) : BoardSpace(space_num), NAME(name), PRICE(price)
{
    owner = nullptr;
}

int PropertySpace::rent()
{
    return 0;
}
