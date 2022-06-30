#ifndef DEED_H
#define DEED_H

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QPushButton>

class PropertySpace;
class Player;

class Deed : public QGraphicsView
{
public:
    Deed(PropertySpace *, QWidget * = nullptr);
    void setPlayer(Player *);

private:
    QGraphicsScene *scene;
    QGraphicsPixmapItem *item;
    QPushButton *buy_btn;
    QPushButton *auction_btn;
    Player *player;
};

#endif // DEED_H
