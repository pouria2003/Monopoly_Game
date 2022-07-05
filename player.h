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
         InJail, Normal, Broke, Lost
    };
    int out_of_jail_num;


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
    void goToJail();
    void getOutOfJail();
    void moveToGo();
    void moveBackThreePlace();

private:
    PlayerInfo *player_info;
    QString name;
    PlayerState state;
    PlayerColor player_color;
    int current_sit;
    int money;
    int  dice_num;
    int back_num;
    QTimer *timer_move;
    QTimer *timer_move_to_jail;
    QTimer *timer_move_to_go;
    QTimer *timer_move_back;

public slots:
    void moveOne();
    void moveOneToJail();
    void moveOneToGo();
    void moveBack();

};

#endif // PLAYER_H
