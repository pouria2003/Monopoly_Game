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

//    players[current_player_index]->changeMoney(-1);



//    players_money[current_player_index]->setPlainText(QString::number(players[current_player_index]->getMoney()) + "$");

Monopoly * Monopoly::_instance = nullptr;

QGraphicsTextItem *addPlayerInfoText (QString name, int money, int ith);
PlayerInfo *addPlayerInfobf(int ith);
QGraphicsTextItem * addMoney(int ith);

Monopoly::Monopoly(){}


Monopoly *Monopoly::instance()
{
    return _instance;
}

void Monopoly::start(const QVector<QString> &players_info)
{
    scene = new QGraphicsScene(this);
    this->setScene(scene);
    scene->setSceneRect(-50, -50, 1100, 800);

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
    property_spaces[12] = new Utility(12, ("اداره برق"), 150);
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
    property_spaces[28] = new Utility(28, ("سازمان آب"), 150);
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

// ######################################### PLAYERS MONEY #####################################
        for(int i = 0; i < players_num; ++i) {
            players_money << addMoney(i);
        }

// ######################################### TASS LOGIC #######################################

        tass_rse = 0;
        current_player_index = 0;

        tass_btn = new QPushButton("TASS", this);

        QColor col = QColor(Qt::green);
        if(col.isValid()) {
           QString qss = QString("background-color: %1").arg(col.name());
           tass_btn->setStyleSheet(qss);
           tass_btn->setFont(QFont("Georgia", 10, QFont::Bold));
        }
        tass_btn->setGeometry(350, 600, 100, 40);
        connect(tass_btn, SIGNAL(clicked()), this, SLOT(tass()));

}


// create instance of Monopoly
Monopoly * Monopoly::createInstance()
{
    if(_instance == nullptr)
        _instance = new Monopoly();
    return _instance;
}

// role the tass and emit move
void Monopoly::tass()
{
    tass_rse = dice1->tass() + dice2->tass();
    emit Monopoly::move();
}

// set buttons disable and call move() for player
void Monopoly::move()
{
    this->disableButtons();
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
    emit next();
}

void Monopoly::next()
{
    this->enableButtons();
    current_player_index += 1;
    current_player_index %= players.size();
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

// funtion to handle players request to buy a property
void Monopoly::buyPropertyForPlayer()
{
    Player *player = players[current_player_index];
    int space_num = players[current_player_index]->getCurrentSit();
    if(player->getMoney() < property_spaces[space_num]->PRICE)
        return;
    player->changeMoney(-property_spaces[space_num]->PRICE);
    property_spaces[space_num]->owner = player;
    setPropertyOwner(player, space_num);

}

void Monopoly::disableButtons()
{
    tass_btn->setDisabled(true);
}

void Monopoly::enableButtons()
{
    tass_btn->setDisabled(false);
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

// funtion to get rent of player if player is on another player property
void Monopoly::getRent(Player * player, int rent)
{
    qDebug() << "in getRent 1";

    player->changeMoney(rent);

    qDebug() << "in getRent 2";

}

// function to change player money text on scene
void Monopoly::moneyChanged()
{
    players_money[current_player_index]->setPlainText(QString::number(players[current_player_index]->getMoney())+ "$");
}
