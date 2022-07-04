#include "board.h"
#include <QPixmap>

Board::Board(QGraphicsItem * parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/Images/board.jpg").scaled(700, 700));
}

QPoint Board::ithPoint(int ith)
{
    ith %= 40;
    if (ith % 10 == 0) {
        switch (ith) {
        case 0: return QPoint(610, 630);
        case 10: return QPoint(70, 630);
        case 20: return QPoint(70, 50);
        case 30: return QPoint(610, 50);
        }
    }
    else if (ith % 10 == 1) {
        switch (ith) {
        case 1: return QPoint(540, 630);
        case 11: return QPoint(70, 560);
        case 21: return QPoint(135, 50);
        case 31: return QPoint(610, 125);
        }
    }
    else {
        switch (ith / 10) {
        case 0: return QPoint(540 - ((ith % 10 ) - 1) * 50, 630);
        case 1: return QPoint(70, 560 - ((ith % 10 ) - 1) * 54);
        case 2: return QPoint(135 + ((ith % 10 ) - 1) * 50, 50);
        case 3: return QPoint(610, 125 + ((ith % 10 ) - 1) * 54);
        }
    }
}


