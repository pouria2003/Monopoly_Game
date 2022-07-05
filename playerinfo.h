#ifndef PLAYERINFO_H
#define PLAYERINFO_H

#include <QGraphicsPixmapItem>

class Player;

class PlayerInfo : public QGraphicsPixmapItem
{
public:
    PlayerInfo(Player *, QGraphicsItem * = nullptr);
    int getMoney();

public:
    int money;
public:
    Player *player;
    QGraphicsTextItem *name_txt;
//    QGraphicsTextItem *money_txt;
    QGraphicsPixmapItem *player_color;

};

#endif // PLAYERINFO_H
