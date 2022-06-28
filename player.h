#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
#include "playerinfo.h"

enum PlayerColor {
    RED = 0, BLUE, GREEN,
    GRAY, YELLOW, ORANGE,
    PURPLE, PINK
};

class Player : public QGraphicsPixmapItem
{
public:

    enum PlayerState {
        NotStarted, InJail, Normal, Broke
    };

public:
    Player(const QString & name, PlayerColor color, QGraphicsItem * = nullptr);
    QString getName();
    void setState(PlayerState);
    PlayerState getState();
private:
    PlayerInfo *player_info;
    QString name;
    PlayerState state;



};

#endif // PLAYER_H
