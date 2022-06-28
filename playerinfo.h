#ifndef PLAYERINFO_H
#define PLAYERINFO_H

#include <QGraphicsPixmapItem>

class Player;

class PlayerInfo : public QGraphicsPixmapItem
{
public:
    PlayerInfo(Player *, QGraphicsItem * = nullptr);
    int getMoney();
    void alterMoney(int);
public:
    int money;
private:
    Player *player;
    QGraphicsTextItem *name_txt;
    QGraphicsTextItem *money_txt;
};

#endif // PLAYERINFO_H
