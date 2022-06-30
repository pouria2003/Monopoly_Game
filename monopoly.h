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
    void getRent(PropertySpace *);
    void moneyChanged();

public slots:
    void tass();
    void move();
    void done();
    void next();
    void buyPropertyForPlayer(Player *, int space_num);
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
    Dice *dice1;
    Dice *dice2;
    int current_player_index;
    int tass_rse;
    QPushButton *tass_btn;


};

#endif // MONOPOLY_H
