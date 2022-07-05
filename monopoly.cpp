#include "monopoly.h"
#include "board.h"
#include "playerlist.h"
#include "playerinfo.h"
#include "player.h"
#include <windows.h>
#include "dice.h"
#include <QVector>
#include <QThread>
#include <QTimer>
#include "deedcontainer.h"
#include <QPushButton>
#include "street.h"
#include "station.h"
#include "utility.h"
#include "nonpropertyspace.h"
#include "deedcontainer.h"
#include <exception>
#include "paidrentcontainer.h"
#include "auctioncontainer.h"
#include "injail.h"
#include "buildcontainer.h"
#include "chance_chest_container.h"
#include "sellcontainer.h"
#include "mortgagecontainer.h"
#include "tradecontainer.h"


Monopoly * Monopoly::_instance = nullptr;

Monopoly::Monopoly(){}

Monopoly *Monopoly::instance()
{
    return _instance;
}

void Monopoly::start(const QVector<QString> &players_info)
{
    deed_container = new DeedContainer(this);
    paid_rent_container = new PaidRentContainer(this);


    scene = new QGraphicsScene(this);
    this->setScene(scene);
    scene->setSceneRect(-50, -20, 1100, 800);

    setBackgroundBrush(QBrush(QImage(":/Images/main_bg.png")));

    Board *board = new Board;
    scene->addItem(board);

    this->setFixedSize(1100, 800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

// ######################################## SPACES ##############################################

    property_spaces[1] = new Street(1, StreetColor::SC_BROWN,( "شهرک ولیعصر" ), 60, 2, 10, 30 ,90, 160, 250, 50, 30);
    property_spaces[3] = new Street(3, StreetColor::SC_BROWN, ("سی متری جی"), 60, 4, 20, 60, 180, 320, 450, 50, 30);
    property_spaces[5] = new Station(5, ("BRT ایستگاه"), 200, 25, 50, 100, 200, 100);
    property_spaces[6] = new Street(6, StreetColor::SC_LIGHTBLUE, ("میدان آزادی"), 100, 6, 30, 90, 270, 400, 550, 50, 50);
    property_spaces[8] = new Street(8, StreetColor::SC_LIGHTBLUE, ("میدان انقلاب"), 100, 6, 30, 90, 270, 400, 550, 50, 50);
    property_spaces[9] = new Street(9, StreetColor::SC_LIGHTBLUE, ("میدان جمهوری"), 120, 8, 40, 100, 300, 450, 600, 50, 60);
    property_spaces[11] = new Street(11, StreetColor::SC_PINK, ("خیابان ستارخان"), 140, 10, 50, 150, 450, 625, 750, 100, 70);
    property_spaces[12] = new Utility(12, ("اداره برق"), 150, 150);
    property_spaces[13] = new Street(13, StreetColor::SC_PINK, ("میدان آریاشهر"), 140, 10, 50, 150, 450, 625, 750, 100, 70);
    property_spaces[14] = new Street(14, StreetColor::SC_PINK, ("میدان فردوسی"), 160, 12, 60, 180, 500, 700, 900, 100, 80);
    property_spaces[15] = new Station(15, ("ایستگاه ترمینال"), 200, 25, 50, 100, 200, 100);
    property_spaces[16] = new Street(16, StreetColor::SC_ORANGE, ("میدان پونک"), 180, 14, 70, 200, 550, 750, 950, 100, 90);
    property_spaces[18] = new Street(18, StreetColor::SC_ORANGE, ("خیابان ولیعصر"), 180, 14, 70, 200, 550, 750, 950, 100, 90);
    property_spaces[19] = new Street(19, StreetColor::SC_ORANGE, ("خیابان شریعتی"), 200, 16, 80, 220, 600, 800, 1000, 100, 100);
    property_spaces[21] = new Street(21, StreetColor::SC_RED, ("شهرک غرب"), 220, 18, 90, 250, 700, 875, 1050, 150, 110);
    property_spaces[23] = new Street(23, StreetColor::SC_RED, ("میدان ونک"), 220, 18, 90, 250, 700, 875, 1050, 150, 110);
    property_spaces[24] = new Street(24, StreetColor::SC_RED, ("میدان تجریش"), 240, 20, 100, 300, 750, 925, 1100, 150, 120);
    property_spaces[25] = new Station(25, ("ایستگاه راه آهن"), 200, 25, 50, 100, 200, 100);
    property_spaces[26] = new Street(26, StreetColor::SC_YELLOW, ("خیابان میرداماد"), 260, 22, 110, 330, 800, 975, 1150, 150, 130);
    property_spaces[27] = new Street(27, StreetColor::SC_YELLOW, ("خیابان پاسداران"), 260, 22, 110, 330, 800, 975, 1150, 150, 130);
    property_spaces[28] = new Utility(28, ("سازمان آب"), 150, 150);
    property_spaces[29] = new Street(29, StreetColor::SC_YELLOW, ("خیابان جردن"), 280, 24, 120, 360, 850, 1025, 1200, 150, 140);
    property_spaces[31] = new Street(31, StreetColor::SC_GREEN, ("منطقه الهیه"), 300, 26, 130, 390, 900, 1100, 1275, 200, 150);
    property_spaces[32] = new Street(32, StreetColor::SC_GREEN, ("منطقه نیاوران"), 300, 26, 130, 390, 900, 1100, 1275, 200, 150);
    property_spaces[34] = new Street(34, StreetColor::SC_GREEN, ("منطقه ولنجک"), 320, 28, 150, 450, 1000, 1200, 1400, 200, 160);
    property_spaces[35] = new Station(35, ("ایستگاه مترو"), 200, 25, 50, 100, 200, 100);
    property_spaces[37] = new Street(37, StreetColor::SC_BLUE, ("منطقه قیطریه"), 350, 35, 175, 500, 1100, 1300, 1500, 200, 175);
    property_spaces[39] = new Street(39, StreetColor::SC_BLUE, ("منطقه زعفرانیه"), 400, 50, 200, 600, 1400, 1700, 2000, 200, 200);

    non_property_spaces[0] = new NonPropertySpace(0, NonPropertySpaceKind::Go);
    non_property_spaces[2] = new NonPropertySpace(2, NonPropertySpaceKind::Chest);
    non_property_spaces[4] = new NonPropertySpace(4, NonPropertySpaceKind::IncomeTax);
    non_property_spaces[7] = new NonPropertySpace(7, NonPropertySpaceKind::Chance);
    non_property_spaces[10] = new NonPropertySpace(10, NonPropertySpaceKind::Jail);
    non_property_spaces[17] = new NonPropertySpace(17, NonPropertySpaceKind::Chest);
    non_property_spaces[20] = new NonPropertySpace(20, NonPropertySpaceKind::FreeParking);
    non_property_spaces[22] = new NonPropertySpace(22, NonPropertySpaceKind::Chance);
    non_property_spaces[30] = new NonPropertySpace(30, NonPropertySpaceKind::GoToJail);
    non_property_spaces[33] = new NonPropertySpace(33, NonPropertySpaceKind::Chest);
    non_property_spaces[36] = new NonPropertySpace(36, NonPropertySpaceKind::Chance);
    non_property_spaces[38] = new NonPropertySpace(38, NonPropertySpaceKind::SuperTax);

    group_sites[StreetColor::SC_BROWN] = new int[3]{1, 3, -1};
    group_sites[StreetColor::SC_LIGHTBLUE] = new int[3]{6, 8, 9};
    group_sites[StreetColor::SC_PINK] = new int[3]{11, 13, 14};
    group_sites[StreetColor::SC_ORANGE] = new int[3]{16, 18, 19};
    group_sites[StreetColor::SC_RED] = new int[3]{21, 23, 24};
    group_sites[StreetColor::SC_YELLOW] = new int[3]{26, 27, 29};
    group_sites[StreetColor::SC_GREEN] = new int[3]{31, 32, 34};
    group_sites[StreetColor::SC_BLUE] = new int[3]{37, 39, -1};

// ######################################## PROPERTY OWNER ##############################################
    space_owner[1] = nullptr;
    space_owner[3] = nullptr;
    space_owner[5] = nullptr;
    space_owner[6] = nullptr;
    space_owner[8] = nullptr;
    space_owner[9] = nullptr;
    space_owner[11] = nullptr;
    space_owner[12] = nullptr;
    space_owner[13] = nullptr;
    space_owner[14] = nullptr;
    space_owner[15] = nullptr;
    space_owner[16] = nullptr;
    space_owner[18] = nullptr;
    space_owner[19] = nullptr;
    space_owner[21] = nullptr;
    space_owner[23] = nullptr;
    space_owner[24] = nullptr;
    space_owner[25] = nullptr;
    space_owner[26] = nullptr;
    space_owner[27] = nullptr;
    space_owner[28] = nullptr;
    space_owner[29] = nullptr;
    space_owner[31] = nullptr;
    space_owner[32] = nullptr;
    space_owner[34] = nullptr;
    space_owner[35] = nullptr;
    space_owner[37] = nullptr;
    space_owner[39] = nullptr;

// ######################################## DICES ##############################################
        dice1 = new Dice(DiceColor::White);
        dice2 = new Dice(DiceColor::Black);

        dice1->undefined();
        scene->addItem(dice1);
        dice1->setPos(350, 300);

        dice2->undefined();
        scene->addItem(dice2);
        dice2->setPos(300, 350);

// ######################################## PLAYERS ##############################################
        int players_num = players_info.size();
        for(int i = 0; i < players_num; ++i) {
            players << new Player(players_info[i], (PlayerColor)(i));
            scene->addItem(players[i]);
        }
// ######################################### PLAYERS INFO #####################################

        for(int i = 0; i < players_num; ++i) {
            players_info_part << addPlayerInfo(players[i], i);
        }
        arrow = new QGraphicsPixmapItem(QPixmap(":/Images/arrow.png"));
        arrow->setPos(arrowPoint(current_player_index));
        scene->addItem(arrow);

// ######################################### PLAYERS MONEY #####################################
        for(int i = 0; i < players_num; ++i) {
            players_money << addMoney(i);
        }

// ######################################### TASS LOGIC #######################################

        tass_rse = 0;
        current_player_index = 0;

// ######################################### BUTTONS #######################################

        tass_btn = new QPushButton("TASS", this);
        QColor col = QColor(Qt::green);
        if(col.isValid()) {
           QString qss = QString("background-color: %1").arg(col.name());
           tass_btn->setStyleSheet(qss);
           tass_btn->setFont(QFont("Georgia", 10, QFont::Bold));
        }
        tass_btn->setGeometry(345, 580, 60, 30);
        connect(tass_btn, SIGNAL(clicked()), this, SLOT(tass()));
        connect(tass_btn, SIGNAL(clicked()), this, SLOT(disableTassButton()));

        done_btn = new QPushButton("DONE", this);
        col = QColor(Qt::green);
        if(col.isValid()) {
           QString qss = QString("background-color: %1").arg(col.name());
           done_btn->setStyleSheet(qss);
           done_btn->setFont(QFont("Georgia", 10, QFont::Bold));
        }
        done_btn->setGeometry(410, 580, 60, 30);
        done_btn->setDisabled(true);
        connect(done_btn, SIGNAL(clicked()), this, SLOT(disableDoneButton()));
        connect(done_btn, SIGNAL(clicked()), this, SLOT(next()));
        connect(done_btn, SIGNAL(clicked()), this, SLOT(disableOtherButtons()));

        build_btn = new QPushButton("BUILD", this);
        col = QColor(Qt::green);
        if(col.isValid()) {
           QString qss = QString("background-color: %1").arg(col.name());
           build_btn->setStyleSheet(qss);
           build_btn->setFont(QFont("Georgia", 10, QFont::Bold));
        }
        build_btn->setGeometry(110, 730, 130, 45);
        build_btn->setDisabled(true);
        connect(build_btn, SIGNAL(clicked()), this, SLOT(buildClicked()));

        sell_btn = new QPushButton("SELL", this);
        col = QColor(Qt::green);
        if(col.isValid()) {
           QString qss = QString("background-color: %1").arg(col.name());
           sell_btn->setStyleSheet(qss);
           sell_btn->setFont(QFont("Georgia", 10, QFont::Bold));
        }
        sell_btn->setGeometry(255, 730, 130, 45);
        sell_btn->setDisabled(true);
        connect(sell_btn, SIGNAL(clicked()), this, SLOT(sellClicked()));

        mortgage_btn = new QPushButton("MORGAGE", this);
        col = QColor(Qt::green);
        if(col.isValid()) {
           QString qss = QString("background-color: %1").arg(col.name());
           mortgage_btn->setStyleSheet(qss);
           mortgage_btn->setFont(QFont("Georgia", 10, QFont::Bold));
        }
        mortgage_btn->setGeometry(400, 730, 130, 45);
        mortgage_btn->setDisabled(true);
        connect(mortgage_btn, SIGNAL(clicked()), this, SLOT(mortgageClicked()));

        trade_btn = new QPushButton("TRADE", this);
        col = QColor(Qt::green);
        if(col.isValid()) {
           QString qss = QString("background-color: %1").arg(col.name());
           trade_btn->setStyleSheet(qss);
           trade_btn->setFont(QFont("Georgia", 10, QFont::Bold));
        }
        trade_btn->setGeometry(545, 730, 130, 45);
        trade_btn->setDisabled(true);

        connect(trade_btn, SIGNAL(clicked()), this, SLOT(tradeClicked()));

        auction_container = new AuctionContainer(players_info.size(), this);

// #################################### IN JAIL ########################################
        in_jail = new InJail(this);
        in_jail->hide();
        connect(in_jail->use_card, SIGNAL(clicked()), this, SLOT(getOutOfJailCard()));
        connect(in_jail->role_dice, SIGNAL(clicked()), this, SLOT(getOutOfJailDice()));
        connect(in_jail->pay, SIGNAL(clicked()), this, SLOT(getOutOfJailPay()));

        connect(in_jail->use_card, SIGNAL(clicked()), in_jail, SLOT(hide()));
        connect(in_jail->role_dice, SIGNAL(clicked()), in_jail, SLOT(hide()));
        connect(in_jail->pay, SIGNAL(clicked()), in_jail, SLOT(hide()));

// #################################### BUILD ########################################
        build_container = new BuildContainer(this);
// #################################### CHANCE CHEST ########################################
        chance_chest_container = new Chance_Chest_Container(this);
// #################################### SELL ########################################
        sell_container = new SellContainer(this);
// #################################### SELL ########################################
        mortgage_container = new MortgageContainer(this);
// #################################### TRADE ########################################
    trade_container = new TradeContainer(this);

}

// create instance of Monopoly
Monopoly * Monopoly::createInstance()
{
    if(_instance == nullptr)
        _instance = new Monopoly();
    return _instance;
}

// role the tass and call move and also return true if dices result is equal
bool Monopoly::tass(bool move)
{

    static int d1, d2;
    d1 = dice1->tass();
    d2 = dice2->tass();

    tass_rse = d1 + d2;
    tass_rse = 1;

    if(move)
        Monopoly::move();

    if(d1 == d2)
        ++equal_dice_num;
    else
        equal_dice_num = 0;

    return d1 == d2;
}

// set buttons disable and call move() for player
void Monopoly::move()
{
    players[current_player_index]->move(tass_rse);
}

// function to do stuff after player moved
void Monopoly::player_done()
{
    int player_sit = players[current_player_index]->getCurrentSit();
    if (property_spaces.contains(player_sit)) {
        property_spaces[player_sit]->playerOn(players[current_player_index]);
    }
    else if (non_property_spaces.contains(player_sit)) {
        non_property_spaces[player_sit]->playerOn(players[current_player_index]);
    }
}

void Monopoly::space_done()
{
    qDebug() << "space done run";

    if(players[current_player_index]->getState() == Player::PlayerState::Broke)
        playerBroked();
    else {
    this->enableDoneButton();
    this->enableOtherButtons();
    }
}

void Monopoly::next()
{
    this->enableTassButton();

    if(equal_dice_num > 0) {
        if(equal_dice_num == 3)
            players[current_player_index]->goToJail();
        else
            return;
    }
    equal_dice_num = 0;
    current_player_index += 1;
    current_player_index %= players.size();
    if(players[current_player_index]->getState() == Player::PlayerState::InJail) {
        disableTassButton();
        playerIsInJail();
    }
//    else if(players[current_player_index]->getState() == Player::PlayerState::Lost)
//        next();
    arrow->setPos(arrowPoint(current_player_index));
}

// function to add Players info to scene
PlayerInfo * Monopoly::addPlayerInfo(Player * player, int ith)
{
    PlayerInfo *player_info = new PlayerInfo(player);
    scene->addItem(player_info);
    player_info->setPos(710, 90 * (ith % 8));
    return player_info;
}

// function to add Players money to scene
QGraphicsTextItem * Monopoly::addMoney(int ith)
{
    QGraphicsTextItem * text = new QGraphicsTextItem;
    text->setPlainText(QString(QString::number(players[ith]->getMoney()) + "$"));
    text->setFont(QFont("Times", 14, QFont::Bold));
    text->setDefaultTextColor(Qt::darkCyan);
    text->setPos(750,  90 * (ith % 8) + 35);
    scene->addItem(text);
    return text;
}

void Monopoly::buyPropertyForPlayer(Player *player, PropertySpace *property, int price)
{
//    Player *player = players[current_player_index];
//    int space_num = players[current_player_index]->getCurrentSit();
//    qDebug() << "in buyPropertyForPlayer   1";
    int space_num = property->space_num;
//    qDebug() << "in buyPropertyForPlayer   2 _ space number = " << space_num;



    if(player->getMoney() < price)
        return;
//    qDebug() << "in buyPropertyForPlayer   3";

    player->changeMoney(-price);
//    qDebug() << "in buyPropertyForPlayer   4";

    property->owner = player;
//    qDebug() << "in buyPropertyForPlayer   5";

    setPropertyOwner(player, property->space_num);
    qDebug() << "in buyPropertyForPlayer _ space_num : " << space_num;

    this->checkIfPropertyGrouped(space_num);

}

void Monopoly::disableTassButton()
{
    tass_btn->setDisabled(true);
}

void Monopoly::enableTassButton()
{
    tass_btn->setDisabled(false);
}

void Monopoly::disableDoneButton()
{
    done_btn->setDisabled(true);
}

void Monopoly::enableDoneButton()
{
    done_btn->setDisabled(false);
}

void Monopoly::disableOtherButtons()
{
    build_btn->setDisabled(true);
    sell_btn->setDisabled(true);
    mortgage_btn->setDisabled(true);
    trade_btn->setDisabled(true);
}

void Monopoly::enableOtherButtons()
{
    build_btn->setDisabled(false);
    sell_btn->setDisabled(false);
    mortgage_btn->setDisabled(false);
    trade_btn->setDisabled(false);
}

void Monopoly::getOutOfJailCard()
{
    players[current_player_index]->out_of_jail_num--;
    players[current_player_index]->getOutOfJail();
    enableTassButton();
}

void Monopoly::getOutOfJailDice()
{
    if(tass(false)) {
        players[current_player_index]->getOutOfJail();
        move();
    }
    else {
        enableDoneButton();
        enableOtherButtons();
    }
}

void Monopoly::getOutOfJailPay()
{
    players[current_player_index]->getOutOfJail();
    players[current_player_index]->changeMoney(-100);
    enableTassButton();
}

void Monopoly::buildClicked()
{
    build_container->createBuild(playersGroupedSites());
    disableOtherButtons();

}

void Monopoly::buildSit(int space_num)
{
    qDebug() << "first of build sit";
    int lvl = property_spaces[space_num]->level + 1;
    QString image_path;
    if(lvl < 5)
        image_path = ":/Images/Houses/h" + QString::number(lvl) + ".png";
    else
        image_path = ":/Images/Houses/hotel.png";

    QPixmap pixmap = QPixmap(image_path);

    if(!house_on_street.contains(space_num)) {
        house_on_street[space_num] = new QGraphicsPixmapItem;
        QPoint point = Board::ithPoint(space_num);
        qDebug() << "in build " << space_num;
        switch(space_num / 10) {
        case 0: house_on_street[space_num]->setPos(point.x(), point.y() - 50); break;
        case 1: house_on_street[space_num]->setPos(point.x() + 30, point.y()); break;
        case 2: house_on_street[space_num]->setPos(point.x(), point.y() + 50); break;
        case 3: house_on_street[space_num]->setPos(point.x() - 50, point.y()); break;
        }
        scene->addItem(house_on_street[space_num]);
    }
    pixmap.scaled(10, 10);
    switch(space_num / 10) {
    case 1: house_on_street[space_num]->setRotation(90); break;
    case 2: house_on_street[space_num]->setRotation(180); break;
    case 3: house_on_street[space_num]->setRotation(270); break;
    }

    house_on_street[space_num]->setPixmap(pixmap);
    qDebug() << "space num : " << space_num;
    qDebug() << "level bood : " <<  property_spaces[space_num]->level;
    property_spaces[space_num]->level++;
    qDebug() << "level shod : " <<  property_spaces[space_num]->level;

    qDebug() << "last of build sit";

    Street *street = dynamic_cast<Street *>(property_spaces[space_num]);
    players[current_player_index]->changeMoney(-street->CONSTRUCTION);

}

void Monopoly::sellClicked()
{
    sell_container->createSell(playerLeveledSites());
    disableOtherButtons();

}

void Monopoly::sellSit(int space_num)
{
    qDebug() << "first of sell sit";
    int lvl = property_spaces[space_num]->level - 1;
    QString image_path;
    image_path = ":/Images/Houses/h" + QString::number(lvl) + ".png";

    QPixmap pixmap = QPixmap(image_path);

//    if(!house_on_street.contains(space_num)) {
//        house_on_street[space_num] = new QGraphicsPixmapItem;
//        QPoint point = Board::ithPoint(space_num);
//        qDebug() << "in build " << space_num;
//        switch(space_num / 10) {
//        case 0: house_on_street[space_num]->setPos(point.x(), point.y() - 50); break;
//        case 1: house_on_street[space_num]->setPos(point.x() + 50, point.y()); break;
//        case 2: house_on_street[space_num]->setPos(point.x(), point.y() + 50); break;
//        case 3: house_on_street[space_num]->setPos(point.x() - 50, point.y()); break;
//        }
//        scene->addItem(house_on_street[space_num]);
//    }
    pixmap.scaled(10, 10);
    house_on_street[space_num]->setPixmap(pixmap);
    qDebug() << "space num : " << space_num;
    qDebug() << "level bood : " <<  property_spaces[space_num]->level;
    property_spaces[space_num]->level--;
    qDebug() << "level shod : " <<  property_spaces[space_num]->level;

    qDebug() << "last of build sit";

    Street *street = dynamic_cast<Street *>(property_spaces[space_num]);
    players[current_player_index]->changeMoney(street->CONSTRUCTION / 2);
}

void Monopoly::mortgageClicked()
{
    mortgage_container->createMortgage(playerProperties());
    disableOtherButtons();

}

void Monopoly::mortgageSit(int space_num)
{
    if(property_spaces[space_num]->in_mortgage) {
        scene->removeItem(mortgage_pixmaps[space_num]);
        mortgage_pixmaps.remove(space_num);

        property_spaces[space_num]->in_mortgage = false;
        property_spaces[space_num]->owner->changeMoney( (-11 * property_spaces[space_num]->MORTGAGE ) / 10);
    }
    else {
        mortgage_pixmaps[space_num] = new QGraphicsPixmapItem(QPixmap(":/Images/mortgage.jpg").scaled(20, 20));
        QPoint point = Board::ithPoint(space_num);
        switch (space_num / 10) {
            case 0: point.setY(point.y() - 60); break;
            case 1: point.setX(point.x() + 55); break;
            case 2: point.setY(point.y() + 55); break;
            case 3: point.setX(point.x() - 60); break;
        }
        mortgage_pixmaps[space_num]->setPos(point);
        scene->addItem(mortgage_pixmaps[space_num]);

        property_spaces[space_num]->in_mortgage = true;
        property_spaces[space_num]->owner->changeMoney(property_spaces[space_num]->MORTGAGE);
    }

}

void Monopoly::tradeClicked()
{
    trade_container->createTrade(current_player_index, &players, &property_spaces);
    disableOtherButtons();
}

void Monopoly::setPropertyOwner(Player *player, int space_num)
{
    QString image_path;
    switch (player->getPlayerColor()) {
        case RED: image_path = ":/Images/red_player.png"; break;
        case BLUE: image_path = ":/Images/blue_player.png"; break;
        case GREEN: image_path = ":/Images/green_player.png"; break;
        case YELLOW: image_path = ":/Images/yellow_player.png"; break;
        case GRAY: image_path = ":/Images/gray_player.png"; break;
        case ORANGE: image_path = ":/Images/orange_player.png"; break;
        case PURPLE: image_path = ":/Images/purple_player.png"; break;
        case PINK: image_path = ":/Images/pink_player.png"; break;
    }

    if(space_owner[space_num] == nullptr) {

        QPoint point = Board::ithPoint(space_num);
        switch (space_num / 10) {
            case 0: point.setY(point.y() + 60); break;
            case 1: point.setX(point.x() - 55); break;
            case 2: point.setY(point.y() - 55); break;
            case 3: point.setX(point.x() + 60); break;
        }

        space_owner[space_num] = new QGraphicsPixmapItem();
        space_owner[space_num]->setPos(point);
        scene->addItem(space_owner[space_num]);
    }
    space_owner[space_num]->setPixmap(QPixmap(image_path).scaled(15, 15));

}

void Monopoly::playerLost()
{
    players[current_player_index]->setState(Player::PlayerState::Lost);
    scene->removeItem(players[current_player_index]);
    players_money[current_player_index]->setPlainText("Lost");
    players_money[current_player_index]->setDefaultTextColor(Qt::red);
}

// funtion to get rent of player if player is on another player property
void Monopoly::getRent(Player * payer, Player *payee, int rent)
{

    payer->changeMoney(-rent);
    payee->changeMoney(rent);

    this->showPaidRent(payer, payee, rent);

}

// function to change player money text on scene
void Monopoly::moneyChanged(Player *player)
{
    players_money[players.indexOf(player)]->setPlainText(QString::number(player->getMoney())+ "$");
}

void Monopoly::showBuyDeed(Player *player, PropertySpace *property)
{
    deed_container->Mshow(property, player);
}

void Monopoly::showPaidRent(Player *payer, Player *payee, int rent)
{
    paid_rent_container->Mshow(payer, payee, rent);
    QTimer::singleShot(2000, paid_rent_container, SLOT(hide()));
}

void Monopoly::auction(PropertySpace *property)
{
    auction_container->createAuction(players, property, current_player_index);
}

void Monopoly::playerIsInJail()
{
    in_jail->Mshow(players[current_player_index]);
}

QVector<int>* Monopoly::playersGroupedSites()
{
    QVector<int> *result = new QVector<int>;
    int *sites;
    bool player_has_group;

    for(int i = 0; i < 8; ++i) {
        player_has_group = true;
        sites = group_sites.value((StreetColor)(i));

         for(int j = 0; j < 3; ++j) {
             if(sites[j] != -1) {
                if(property_spaces[sites[j]]->owner != players[current_player_index]){
                    player_has_group = false;
                    break;
                }

             }
         }
         if(player_has_group) {

             for(int k = 0; k < 3; ++k) {
                 if(sites[k] != -1)
                     result->push_back(sites[k]);
             }

         }
    }
    return result;
}

bool Monopoly::isUpadatable(int space_num)
{
    Street *street = dynamic_cast<Street *>(property_spaces[space_num]);
    int lvl = street->level;
    int *other_sites = group_sites[street->getColor()];

    for(int i = 0; i < 3; ++i) {
        if(other_sites[i] != -1 && ( property_spaces[other_sites[i]]->level < lvl || property_spaces[other_sites[i]]->level == 5) ){
            return false;
        }
    }
    return true;
}

void Monopoly::showChance(int kind, int chance_num)
{
    chance_chest_container->creatChanceChest((NonPropertySpaceKind)kind, chance_num);
    QTimer::singleShot(2000, chance_chest_container, SLOT(close()));


    if(kind == 4 /* chest */ ) {
        switch (chance_num) {
        case 1: players[current_player_index]->moveToGo(); break;
        case 2: players[current_player_index]->changeMoney(100); space_done();break;
        case 3: players[current_player_index]->changeMoney(10); space_done();break;
        case 4: players[current_player_index]->changeMoney(200); space_done();break;
        case 5: players[current_player_index]->changeMoney(20); space_done();break;
        case 6: players[current_player_index]->changeMoney(100); space_done();break;
        case 7: players[current_player_index]->changeMoney(25); space_done();break;
        case 8: players[current_player_index]->changeMoney(-50); space_done();break;
        }
    }
    else if (kind == 5 /* chance */ ) {
        switch (chance_num) {
        case 1: players[current_player_index]->moveToGo(); break;
        case 2: players[current_player_index]->moveBackThreePlace(); break;
        case 3: players[current_player_index]->changeMoney(50); space_done();break;
        case 4: players[current_player_index]->changeMoney(150); space_done();break;
        case 5: players[current_player_index]->changeMoney(-15); space_done();break;
        case 6:
            for(int i = 0; i < players.size(); ++i) {
                if(! (i == current_player_index))
                    players[i]->changeMoney(50);
            }
            players[current_player_index]->changeMoney(-50 * (players.size() - 1)); space_done();break;
        case 7: players[current_player_index]->goToJail(); break;
        case 8: players[current_player_index]->out_of_jail_num++; space_done();break;
        }
    }
}

void Monopoly::checkIfPropertyGrouped(int space_num)
{
    qDebug() << "in check for group_space num : " << space_num;
    if (typeid(*(property_spaces[space_num])) == typeid(Street)) {
        qDebug() << "street bod";

        Street *street = dynamic_cast<Street *>(property_spaces[space_num]);
        int *sites = group_sites[street->getColor()];
        bool is_grouped = true;
        for(int i = 0; i < 3; ++i) {
            if(sites[i] != -1 && property_spaces[sites[i]]->owner != players[current_player_index]) {
                is_grouped = false;
                break;
            }
        }
        if(is_grouped)
            qDebug() << "street ha group shodan";
        for(int i = 0; i < 3; ++i) {
            if(sites[i] != -1){
                street = dynamic_cast<Street *>(property_spaces[sites[i]]);
                street->is_grouped = is_grouped;
            }
        }
    }
    else if (typeid(*(property_spaces[space_num])) == typeid(Station)) {
        qDebug() << "station bod";

        Station *station;
        int number_of_stations = 0;
        for(int i = 1; i <= 7; i += 2) {
            if(property_spaces[i * 5]->owner == players[current_player_index])
                ++number_of_stations;
        }
        for(int i = 1; i <= 7; i += 2) {
            if(property_spaces[i * 5]->owner == players[current_player_index]) {
                station = dynamic_cast<Station *>(property_spaces[i * 5]);
                station->stations_number = number_of_stations;
                qDebug() << "station e " << i * 5 << number_of_stations << "tayee shod";
            }
        }

    }
    else if (typeid(*(property_spaces[space_num])) == typeid(Utility)) {
        qDebug() << "utility bod";

        Utility *utility;
        if(property_spaces[12]->owner == property_spaces[28]->owner) {
            utility = dynamic_cast<Utility *>(property_spaces[12]);
            utility->owned_boath = true;
            utility = dynamic_cast<Utility *>(property_spaces[28]);
            utility->owned_boath = true;
            qDebug() << "utility ha joft shodan";
        }

    }
    else {
        qDebug() << "hichkodom nabod";

    }
}

void Monopoly::getIncomTax()
{
    players[current_player_index]->changeMoney(-100);
}

void Monopoly::getSuperTax()
{
    players[current_player_index]->changeMoney(-1 * ( ( (players[current_player_index]->getMoney() / 10 ) > 200 )
                                                      ? (players[current_player_index]->getMoney() / 10 ) : 200 ) );
}

QPoint Monopoly::arrowPoint(int ith)
{
    return QPoint(920, 90 * (ith % 8) + 20);
}

int Monopoly::dices_num()
{
    return tass_rse;
}

void Monopoly::playerBroked()
{

    if(playerSellsMoney() < -(players[current_player_index]->getMoney())) {
        playerLost();
    }
    else {

        done_btn->setDisabled(true);
        enableOtherButtons();
        build_btn->setDisabled(true);
    }

}

void Monopoly::playerOutOfBroke()
{
    enableOtherButtons();
    enableDoneButton();
}

QVector<int> *Monopoly::playerLeveledSites()
{
    QVector<int> *result = new QVector<int>;
    int *sites;

    for(int i = 0; i < 8; ++i) {
        sites = group_sites[(StreetColor)(i)];
        if(property_spaces[sites[1]]->owner == players[current_player_index] &&
                (dynamic_cast<Street *>(property_spaces[sites[1]]))->level > 0) {
            for(int j = 0; j < 3; ++j) {
                if(sites[j] != -1){
                    result->push_back(sites[j]);
                }
            }
        }
    }
    return result;
}

bool Monopoly::isSelable(int space_num)
{
    if(property_spaces[space_num]->level < 1)
        return false;
    Street *street = dynamic_cast<Street *>(property_spaces[space_num]);
    int lvl = street->level;
    int *sites = group_sites[street->getColor()];
    for(int i = 0; i < 3; ++i) {
        if(sites[i] != -1 && property_spaces[sites[i]]->level > lvl){
            return false;
        }
    }
    return true;
}

bool Monopoly::isMortgageable(int space_num)
{
    if(property_spaces[space_num]->in_mortgage)
        return false;
    if(typeid(*(property_spaces[space_num])) == typeid(Street)
            && property_spaces[space_num]->level != 0)
        return false;
    return true;
}

QVector<int> *Monopoly::playerProperties()
{
    QVector<int> *result = new QVector<int>;
    for(int i = 0; i < 40; ++i) {
        if(property_spaces.contains(i) && property_spaces[i]->owner == players[current_player_index]) {
            if(typeid(*(property_spaces[i])) != typeid(Street) || property_spaces[i]->level == 0)
                result->push_back(i);
        }
    }
    return result;
}

int Monopoly::playerSellsMoney()
{
    int ans = 0;
    for(int i = 0; i < 40; ++i) {
        if(property_spaces.contains(i) && property_spaces[i]->owner == players[current_player_index]) {
            if(typeid(*(property_spaces[i])) == typeid(Street)) {
                ans += (dynamic_cast<Street *>(property_spaces[i]))->level *
                        (dynamic_cast<Street *>(property_spaces[i]))->CONSTRUCTION / 2;
            }
            ans += property_spaces[i]->MORTGAGE;
        }
    }
    return ans;
}
