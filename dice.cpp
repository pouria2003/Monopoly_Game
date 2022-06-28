#include "dice.h"
#include <QRandomGenerator>
#include <QDebug>


Dice::Dice(DiceColor _color, QGraphicsItem *) : color(_color) {}

int Dice::tass()
{
    int result;
    result = QRandomGenerator::global()->bounded(1, 7);
    QString dice_path = QString(":/Images/") + ((color == White) ? QString("white") : QString("black") )
            + QString("_dice") + QString::number(result);

    this->setPixmap(QPixmap(dice_path).scaled(50, 50));

    return result;
}

void Dice::undefined()
{
    QString dice_path = QString(":/Images/undefined_") + ((color == White) ? QString("white") : QString("black") )
            + QString("_dice");

    this->setPixmap(QPixmap(dice_path).scaled(50, 50));
}
