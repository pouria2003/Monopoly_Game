#ifndef PAIDRENT_H
#define PAIDRENT_H

#include <QGraphicsView>

class Player;

class PaidRent : public QGraphicsView
{
public:
    PaidRent(QWidget * = nullptr);
    void setPaidRent(Player *payer, Player *payee, int rent);
public:
    QGraphicsScene *scene;
    QGraphicsPixmapItem *payer_pixmap;
    QGraphicsPixmapItem *payee_pixmap;
    QGraphicsTextItem *payer_txt;
    QGraphicsTextItem *payee_txt;
    QGraphicsTextItem *money_txt;
};

#endif // PAIDRENT_H
