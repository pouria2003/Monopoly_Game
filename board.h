#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPoint>

class Board : public QGraphicsPixmapItem
{
public:
    explicit Board(QGraphicsItem * = nullptr);
    static QPoint ithPoint(int ith);
};

#endif // BOARD_H
