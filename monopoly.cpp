#include "monopoly.h"
#include "board.h"
#include "playerlist.h"
#include "playerinfo.h"
#include "player.h"
#include "dice.h"
#include <QVector>

Monopoly * Monopoly::_instance = nullptr;

QGraphicsTextItem *addPlayerInfoText (QString name, int money, int ith);
PlayerInfo *addPlayerInfobf(int ith);

Monopoly::Monopoly(const QVector<QString> & players_info)
{

    scene = new QGraphicsScene(this);
    this->setScene(scene);
    scene->setSceneRect(-50, -50, 800, 800);

    setBackgroundBrush(QBrush(QImage(":/Images/background1.png")));

    Board *board = new Board;
    scene->addItem(board);

    this->setFixedSize(800, 800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    dice1 = new Dice(DiceColor::White);
    dice2 = new Dice(DiceColor::Black);

        dice1->undefined();
        scene->addItem(dice1);
        dice1->setPos(350, 300);

        dice2->undefined();
        scene->addItem(dice2);
        dice2->setPos(300, 350);

        PlayerList *pl = new PlayerList(players_info);
        pl->start();

// ################################## player info ######################################
//    PlayerInfo *pi = new PlayerInfo(new Player("ali", PlayerColor::BLUE));
//    scene->addItem(pi);
//    pi->setPos(150, -50);

//    PlayerInfo *p1 = new PlayerInfo(new Player("ADSf", PlayerColor::RED));
//    scene->addItem(p1);
//    p1->setPos(0, -50);


//    PlayerInfo *p2 = new PlayerInfo(new Player("ADSf", PlayerColor::RED));
//    scene->addItem(p2);
//    p2->setPos(180, -50);


//    PlayerInfo *p3 = new PlayerInfo(new Player("ADSf", PlayerColor::RED));
//    scene->addItem(p3);
//    p3->setPos(360, -50);


//    PlayerInfo *p4 = new PlayerInfo(new Player("ADSf", PlayerColor::RED));
//    scene->addItem(p4);
//    p4->setPos(540, -50);


//    PlayerInfo *p5 = new PlayerInfo(new Player("ADSf", PlayerColor::RED));
//    scene->addItem(p5);
//    p5->setPos(0, 700);


//    PlayerInfo *p6 = new PlayerInfo(new Player("ADSf", PlayerColor::RED));
//    scene->addItem(p6);
//    p6->setPos(180, 700);

//    PlayerInfo *p7 = new PlayerInfo(new Player("ADSf", PlayerColor::RED));
//    scene->addItem(p7);
//    p7->setPos(360, 700);

//    PlayerInfo *p8 = new PlayerInfo(new Player("ADSf", PlayerColor::RED));
//    scene->addItem(p8);
//    p8->setPos(540, 700);



//    QGraphicsTextItem *t = addPlayerInfoText("ali", 100, 0);
//    QGraphicsTextItem *t1 = addPlayerInfoText("ali", 100, 1);

//    QGraphicsTextItem *t2 = addPlayerInfoText("ali", 100, 2);

//    QGraphicsTextItem *t3 = addPlayerInfoText("ali", 100, 3);

//    QGraphicsTextItem *t4 = addPlayerInfoText("ali", 100, 4);

//    QGraphicsTextItem *t5 = addPlayerInfoText("ali", 100, 5);

//    QGraphicsTextItem *t6 = addPlayerInfoText("ali", 100, 6);
//    QGraphicsTextItem *t7 = addPlayerInfoText("ali", 100, 7);

//    scene->addItem(t);
//    scene->addItem(t+1);

//    scene->addItem(t1);
//    scene->addItem(t1+1);

//    scene->addItem(t2);
//    scene->addItem(t2+1);

//    scene->addItem(t3);
//    scene->addItem(t3+1);

//    scene->addItem(t4);
//    scene->addItem(t4+1);

//    scene->addItem(t5);
//    scene->addItem(t5+1);

//    scene->addItem(t6);
//    scene->addItem(t6+1);

//    scene->addItem(t7);
//    scene->addItem(t7+1);




// ################################# DICE ############################3
//    Dice *d1 = new Dice(DiceColor::White);
//    Dice *d2 = new Dice(DiceColor::Black);

//    d1->tass();
//    scene->addItem(d1);
//    d1->setPos(350, 300);

//    d2->tass();
//    scene->addItem(d2);
//    d2->setPos(300, 350);


}

Monopoly *Monopoly::instance()
{
    return _instance;
}

Monopoly * Monopoly::createInstance(const QVector<QString> &players_info)
{
    if(_instance == nullptr)
        _instance = new Monopoly(players_info);
    qDebug() << "instance changed to " << _instance;
    return _instance;
}

int Monopoly::tass()
{
    return dice1->tass() + dice2->tass();
}

QGraphicsTextItem *addPlayerInfoText (QString name, int money, int ith)
{
    QGraphicsTextItem *info = new QGraphicsTextItem[2];
    info[0].setPlainText(name);
    info[1].setPlainText(QString::number(money) + "$");

    info[0].setFont(QFont("times", 14));
    info[1].setFont(QFont("times", 14, QFont::Bold));

    info[1].setDefaultTextColor(Qt::darkGreen);

    info[0].setPos((ith % 4) * 180, (ith / 4) ? 700 : -50 );
    info[1].setPos((ith % 4) * 180, (ith / 4) ? 725 : -25);
    return info;
}

void Monopoly::addPlayer(Player * player)
{
    scene->addItem(player);
}
