#ifndef CHANCE_CHEST_CONTAINER_H
#define CHANCE_CHEST_CONTAINER_H

#include <QWidget>
#include "nonpropertyspace.h"
#include "chance_chest.h"

class Chance_Chest_Container : public QWidget
{
    Q_OBJECT
public:
    explicit Chance_Chest_Container(QWidget *parent = nullptr);
    void creatChanceChest(NonPropertySpaceKind kind, int num);

private:
    Chance_Chest *chance_chest;
};

#endif // CHANCE_CHEST_CONTAINER_H
