#ifndef CHANCE_CHEST_H
#define CHANCE_CHEST_H

#include "nonpropertyspace.h"

#include <QGraphicsView>


class Chance_Chest : public QGraphicsView
{
public:
    Chance_Chest(QWidget * = nullptr);
    void setChanceChest(NonPropertySpaceKind , int);


private:
    QGraphicsScene *scene;
    QGraphicsPixmapItem *card;
};

#endif // CHANCE_CHEST_H
