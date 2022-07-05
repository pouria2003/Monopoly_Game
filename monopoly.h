#ifndef MONOPOLY_H
#define MONOPOLY_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QHash>
#include "street.h"

class Dice;
class Player;
class PlayerInfo;
class TEst;
class QPushButton;
class PropertySpace;
class NonPropertySpace;
class DeedContainer;
class PaidRentContainer;
class AuctionContainer;
class InJail;
class BuildContainer;
class Chance_Chest_Container;
class SellContainer;
class MortgageContainer;
class TradeContainer;

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
    void getRent(Player *payer, Player *payee, int);
    void moneyChanged(Player *);
    void buyPropertyForPlayer(Player *, PropertySpace *, int);
    void showBuyDeed(Player *, PropertySpace *);
    void showPaidRent(Player *payer, Player *payee, int rent);
    void auction(PropertySpace *);
    void playerIsInJail();
    QVector<int>* playersGroupedSites();
    bool isUpadatable(int space_num);
    void showChance(int, int);
    void checkIfPropertyGrouped(int space_num);
    void getIncomTax();
    void getSuperTax();
    QPoint arrowPoint(int ith);
    int dices_num();
    void playerBroked();
    void playerOutOfBroke();
    QVector<int> *playerLeveledSites();
    bool isSelable(int space_num);
    bool isMortgageable(int space_num);
    QVector<int> *playerProperties();
    int playerSellsMoney();
    void setPropertyOwner(Player *, int);
    void playerLost();




public slots:
    bool tass(bool = true);
    void move();
    void player_done();
    void space_done();
    void next();
    void disableTassButton();
    void enableTassButton();
    void disableDoneButton();
    void enableDoneButton();
    void disableOtherButtons();
    void enableOtherButtons();
    void getOutOfJailCard();
    void getOutOfJailDice();
    void getOutOfJailPay();
    void buildClicked();
    void buildSit(int);
    void sellClicked();
    void sellSit(int);
    void mortgageClicked();
    void mortgageSit(int);
    void tradeClicked();


public:
    QGraphicsScene *scene;

private:
    QVector<QGraphicsTextItem *> players_money;
    QVector<Player *> players;
    QVector<PlayerInfo *> players_info_part;
    QHash<int, QGraphicsPixmapItem *> house_on_street;
    QHash<int, PropertySpace *> property_spaces;
    QHash<int, NonPropertySpace *> non_property_spaces;
    QHash<int, QGraphicsPixmapItem *>space_owner;
    QHash<StreetColor, int *> group_sites;
    QHash<int, QGraphicsPixmapItem *> mortgage_pixmaps;
    Dice *dice1;
    Dice *dice2;
    int current_player_index;
    int tass_rse;
    int equal_dice_num;
    QPushButton *tass_btn;
    QPushButton *done_btn;
    QPushButton *build_btn;
    QPushButton *sell_btn;
    QPushButton *mortgage_btn;
    QPushButton *trade_btn;
    DeedContainer *deed_container;
    PaidRentContainer *paid_rent_container;
    AuctionContainer *auction_container;
    InJail *in_jail;
    BuildContainer *build_container;
    Chance_Chest_Container *chance_chest_container;
    QGraphicsPixmapItem *arrow;
    SellContainer *sell_container;
    MortgageContainer *mortgage_container;
    TradeContainer *trade_container;

};

#endif // MONOPOLY_H
