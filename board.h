#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Board : public QGraphicsPixmapItem
{
public:
    explicit Board(QGraphicsItem * = nullptr);
};

#endif // BOARD_H
