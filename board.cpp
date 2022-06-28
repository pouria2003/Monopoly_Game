#include "board.h"
#include <QPixmap>

Board::Board(QGraphicsItem * parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/Images/board.jpg").scaled(700, 700));
}
