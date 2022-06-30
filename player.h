#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
#include "playerinfo.h"

enum PlayerColor {
    RED = 0, BLUE, GREEN,
    GRAY, YELLOW, ORANGE,
    PURPLE, PINK
};

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    enum PlayerState {
        NotStarted, InJail, Normal, Broke
    };

public:
    Player(const QString & name, PlayerColor color, QGraphicsItem * = nullptr);
    QString getName();
    void setState(PlayerState);
    PlayerState getState();
    PlayerColor getPlayerColor();
    void move(int dice_num);
    void changeMoney(int diff);
    int getMoney();
    int getCurrentSit();

private:
    PlayerInfo *player_info;
    QString name;
    PlayerState state;
    PlayerColor player_color;
    int current_sit;
    int money;
    int  dice_num;
    QTimer *timer_move;

public slots:
    void moveOne();
};

#endif // PLAYER_H
