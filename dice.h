#ifndef DICE_H
#define DICE_H

#include <QGraphicsPixmapItem>

enum DiceColor {
    White, Black
};

class Dice : public QGraphicsPixmapItem
{
public:
    Dice(DiceColor color, QGraphicsItem * = nullptr);
    int tass();
    void undefined();

private:
    DiceColor color;
};

#endif // DICE_H
