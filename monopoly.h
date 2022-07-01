#ifndef MONOPOLY_H
#define MONOPOLY_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QHash>

class Dice;
class Player;
class PlayerInfo;
class TEst;
class QPushButton;
class PropertySpace;
class NonPropertySpace;

class Monopoly : public QGraphicsView
{
    Q_OBJECT
private:
    Monopoly();
    PlayerInfo * addPlayerInfo(Player *, int ith);

private:
    static Monopoly * _instance;

public:
    static Monopoly * createInstance();
    static Monopoly * instance();
    void start(const QVector<QString> & player_info);
    QGraphicsTextItem * addMoney(int ith);
    void getRent(Player *, int);
    void moneyChanged();
    void buyPropertyForPlayer();


public slots:
    void tass();
    void move();
    void player_done();
    void space_done();
    void next();
    void disableButtons();
    void enableButtons();

public:
    QGraphicsScene *scene;

private:
    QVector<QGraphicsTextItem *> players_money;
    QVector<Player *> players;
    QVector<PlayerInfo *> players_info_part;
    QHash<int, PropertySpace *> property_spaces;
    QHash<int, NonPropertySpace *> non_property_spaces;
    QHash<int, QGraphicsPixmapItem *>space_owner;
    Dice *dice1;
    Dice *dice2;
    int current_player_index;
    int tass_rse;
    QPushButton *tass_btn;
    void setPropertyOwner(Player *, int);

};

#endif // MONOPOLY_H
