#ifndef AUCTION_H
#define AUCTION_H

#include <QGraphicsView>

class Player;
class PropertySpace;
class QSlider;
class QPushButton;
class QLabel;
class AuctionContainer;

class Auction : public QGraphicsView
{
    Q_OBJECT
public:
    Auction(int players_number, AuctionContainer *, QWidget * = nullptr);
    void setAuction(const QVector<Player *> & players, PropertySpace *property, int);
    static QPoint ithPlayerInfo(int ith);

private:
    void nextPlayer();
    void finishAuction();

public slots:
    void next();
    void fold();
    void bided();

private:
    AuctionContainer *container;
    int players_number;
    int current_player_index;
    int non_fold_players_number;
    int winner_index;
    int max_price;
    PropertySpace *property;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *deed;
    QGraphicsPixmapItem **back_grounds;
    QGraphicsTextItem **names;
    QGraphicsTextItem **money;
    QGraphicsItemGroup **players_info;
    QSlider *slider;
    QLabel *money_lbl;
    QPushButton *bid_btn;
    QPushButton *fold_btn;
    QVector<Player *> players;
    bool *is_fold;


};
#endif // AUCTION_H
