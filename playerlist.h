#ifndef PLAYERLIST_H
#define PLAYERLIST_H

#include <QString>
#include <QVector>

class Player;

class PlayerList
{

public:
    PlayerList(const QVector<QString> & players_info);
    void start();

private:
    QVector<Player *> players;
};

#endif // PLAYERLIST_H
