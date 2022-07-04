#ifndef AUCTIONCONTAINER_H
#define AUCTIONCONTAINER_H

#include <QWidget>

class Auction;
class Player;
class PropertySpace;

class AuctionContainer : public QWidget
{
    Q_OBJECT
public:
    explicit AuctionContainer(int players_number, QWidget *parent = nullptr);
    void createAuction(const QVector<Player *> & players, PropertySpace *property, int current_player_index);

private:
    Auction *auction;
};

#endif // AUCTIONCONTAINER_H
