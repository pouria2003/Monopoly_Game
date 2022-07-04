#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include "auction.h"
#include "player.h"
#include "street.h"
#include "QTimer"
#include "station.h"
#include "monopoly.h"
#include "auctioncontainer.h"

Auction::Auction(int players_number, AuctionContainer *_container, QWidget * parent)
    : QGraphicsView(parent), container(_container)
{
    scene = new QGraphicsScene();
    this->setScene(scene);

    QGraphicsPixmapItem *bg = new QGraphicsPixmapItem(QPixmap(":/Images/auction/auction.png"));
    scene->addItem(bg);

    players_info = new QGraphicsItemGroup *[players_number];

    back_grounds = new QGraphicsPixmapItem *[players_number];

    names = new QGraphicsTextItem *[players_number];

    money = new QGraphicsTextItem *[players_number];



    slider = new QSlider(Qt::Orientation::Horizontal, this);
    slider->setGeometry(90, 470, 300, 20);

    money_lbl = new QLabel("100", this);
    money_lbl->setStyleSheet("QLabel { color : darkGreen; } ");
    money_lbl->setFont(QFont("Times", 14, QFont::Bold));
    money_lbl->setGeometry(225, 430, 50, 20);

    bid_btn = new QPushButton("BID", this);
    QColor col = QColor(Qt::green);
    if(col.isValid()) {
       QString qss = QString("background-color: %1").arg(col.name());
       bid_btn->setStyleSheet(qss);
       bid_btn->setFont(QFont("Georgia", 10, QFont::Bold));
    }
    bid_btn->setGeometry(140, 520, 80, 35);

    fold_btn = new QPushButton("FOLD", this);
    col = QColor(Qt::red);
    if(col.isValid()) {
       QString qss = QString("background-color: %1").arg(col.name());
       fold_btn->setStyleSheet(qss);
       fold_btn->setFont(QFont("Georgia", 10, QFont::Bold));
    }
    fold_btn->setGeometry(250, 520, 80, 35);

    connect(slider, SIGNAL(valueChanged(int)), money_lbl, SLOT(setNum(int)));
    connect(bid_btn, SIGNAL(clicked()), this, SLOT(bided()));
    connect(fold_btn, SIGNAL(clicked()), this, SLOT(fold()));

}

void Auction::setAuction(const QVector<Player *> &_players, PropertySpace *_property, int _current_player_index)
{
//    qDebug() << "in Auction::setAuction";
    players = _players;
    players_number = players.size();
    property = _property;
//    qDebug() << players_number;
    non_fold_players_number = players_number;
    current_player_index = _current_player_index;
    max_price = 0;
    winner_index = 0;

    if(typeid(*(property)) == typeid(Street)) {
        deed = new QGraphicsPixmapItem(QPixmap
                                       (":/Images/deed/deed_" + QString::number(property->space_num) + ".png").scaled(200, 300));
    }
    else if (typeid(*(property)) == typeid(Station)) {
         deed = new QGraphicsPixmapItem(QPixmap(":/Images/deed/deed_station.png").scaled(200, 300));
    }
    deed->setPos(50, 100);

    for(int j = 0, i = current_player_index; j < players_number; ++j) {

        players_info[i] = new QGraphicsItemGroup();

        QString image_path;
        switch (players[i]->getPlayerColor()) {
            case RED: image_path = ":/Images/auction/auction_bg_red.png"; break;
            case BLUE: image_path = ":/Images/auction/auction_bg_blue.png"; break;
            case GREEN: image_path = ":/Images/auction/auction_bg_green.png"; break;
            case YELLOW: image_path = ":/Images/auction/auction_bg_yellow.png"; break;
            case GRAY: image_path = ":/Images/auction/auction_bg_gray.png"; break;
            case ORANGE: image_path = ":/Images/auction/auction_bg_orange.png"; break;
            case PURPLE: image_path = ":/Images/auction/auction_bg_purple.png"; break;
            case PINK: image_path = ":/Images/auction/auction_bg_pink.png"; break;
        }

        back_grounds[i] = new QGraphicsPixmapItem(QPixmap(image_path).scaled(150, 35), players_info[i]);
        players_info[i]->addToGroup(back_grounds[i]);
        names[i] = new QGraphicsTextItem(players[i]->getName(), players_info[i]);
        names[i]->setPos(10, 0);
        names[i]->setFont(QFont("Times", 14));
        players_info[i]->addToGroup(names[i]);
        money[i] = new QGraphicsTextItem(QString::number(0), players_info[i]);
        money[i]->setPos(100, 0);
        money[i]->setFont(QFont("Times", 14));
        players_info[i]->addToGroup(money[i]);

        players_info[i]->setPos(ithPlayerInfo(j));

        scene->addItem(players_info[i]);

        ++i;
        i %= players_number;
    }

    scene->addItem(deed);

    money_lbl->setNum(max_price + 1);
    slider->setMinimum(1);
    slider->setMaximum(players[current_player_index]->getMoney());

//    qDebug() << "end of Auction::setAuction";
    is_fold = new bool[players_number];
    for(int i = 0; i < players_number; ++i)
        is_fold[i] = false;

}

void Auction::bided()
{
//    qDebug() << "in bided";
    max_price = money_lbl->text().toInt();
    winner_index = current_player_index;
    money[current_player_index]->setPlainText(QString::number(max_price));
    next();
}

QPoint Auction::ithPlayerInfo(int ith)
{
    switch (ith) {
    case 0: return QPoint(280, 100);
    case 1: return QPoint(280, 140);
    case 2: return QPoint(280, 180);
    case 3: return QPoint(280, 220);
    case 4: return QPoint(280, 260);
    case 5: return QPoint(280, 300);
    case 6: return QPoint(280, 340);
    case 7: return QPoint(280, 380);
    case 8: return QPoint(280, 420);
    default: return QPoint(280, 100);
    }
}

void Auction::next()
{

    if(bid_btn->isEnabled() == false) {
        bid_btn->setEnabled(true);
        slider->setEnabled(true);
    }

//    qDebug() << current_player_index <<players[current_player_index]->getName() << " clicked";
    for(int i = 0; i < players_number; ++i) {
        if(is_fold[i])
            continue;
        players_info[i]->setPos(players_info[i]->pos().x(), players_info[i]->pos().y() + 40);
        if(players_info[i]->pos().y() > ithPlayerInfo(non_fold_players_number - 1).y())
            players_info[i]->setPos(players_info[i]->pos().x(), 100);
    }
    nextPlayer();

    money_lbl->setNum(max_price + 1);
    if(players[current_player_index]->getMoney() < max_price + 1) {
        bid_btn->setEnabled(false);
        slider->setEnabled(false);
    }
    else {
        slider->setMinimum(max_price + 1);
        slider->setMaximum(players[current_player_index]->getMoney());
    }
}

void Auction::fold()
{
//    qDebug() << current_player_index <<players[current_player_index]->getName() << " clicked";
    is_fold[current_player_index] = true;
    scene->removeItem(players_info[current_player_index]);

    --non_fold_players_number;
    if(non_fold_players_number == 1) {
        finishAuction();
    }

    nextPlayer();

    for(int i = 0; i < players_number; ++i) {
        if(players_info[i]->pos().y() == ithPlayerInfo(non_fold_players_number).y() ) {
            players_info[i]->setPos(players_info[i]->pos().x(), 100);
            break;
        }
    }

}

void Auction::nextPlayer()
{
    --current_player_index;
    if(current_player_index == -1)
        current_player_index = players_number - 1;
    if(is_fold[current_player_index])
        nextPlayer();
}

void Auction::finishAuction()
{

    if(max_price != 0) {
        Monopoly::instance()->buyPropertyForPlayer(players[winner_index], property, max_price);
    }

    qDebug() << "in finish Auction 1";
//    qDebug() << "winner is " << players[winner_index]->getName();
    qDebug() << "in finish Auction 2";

    Monopoly::instance()->space_done();
    qDebug() << "in finish Auction 3";

    container->hide();
    qDebug() << "in finish Auction 4";

}
