#ifndef MONOPOLY_H
#define MONOPOLY_H

#include <QGraphicsView>
#include <QGraphicsScene>

class Dice;
class Player;

class Monopoly : public QGraphicsView
{
private:
    Monopoly(const QVector<QString>& players_info);

private:
    static Monopoly * _instance;

public:
    static Monopoly * createInstance(const QVector<QString> & player_info);
    static Monopoly * instance();
    int tass();
    void addPlayer(Player *);

public:
    QGraphicsScene *scene;

private:
    Dice *dice1;
    Dice *dice2;
};

#endif // MONOPOLY_H
