#include "chance_chest_container.h"

Chance_Chest_Container::Chance_Chest_Container(QWidget *parent)
    : QWidget{parent}
{
    chance_chest = new Chance_Chest(this);
    this->hide();
    this->setGeometry(100, 150, 433, 253);
}

void Chance_Chest_Container::creatChanceChest(NonPropertySpaceKind kind, int num)
{
    chance_chest->setChanceChest(kind, num);
    this->show();
}


