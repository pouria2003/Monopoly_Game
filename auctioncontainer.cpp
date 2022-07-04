#include "auctioncontainer.h"
#include "auction.h"
#include <QDebug>

AuctionContainer::AuctionContainer(int players_number, QWidget *parent)
    : QWidget{parent}
{
    this->setGeometry(150, 0, 480, 610);
    auction = new Auction(players_number, this, this);
    this->hide();
}

void AuctionContainer::createAuction(const QVector<Player *> &players, PropertySpace *property, int current_player_index)
{
    qDebug() << "in AuctionContainer::creatAuction";
    auction->setAuction(players, property, current_player_index);
    this->show();
}

