#include "deed.h"
#include "propertyspace.h"
#include <QGraphicsTextItem>
#include "street.h"
#include "station.h"
#include "player.h"
#include "monopoly.h"
#include <typeinfo>
#include "deedcontainer.h"
#include "utility.h"

Deed::Deed(DeedContainer *_container, QWidget *p)
    : QGraphicsView(p), container(_container)
{}

void Deed::setDeed(PropertySpace *_property, Player *_player)
{
    scene = new QGraphicsScene;

    player = _player;
    property = _property;

    this->setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    QString image_path;
    if (typeid(*(property)) == typeid(Street)) {

        Street *street = dynamic_cast<Street *>(property);

        switch(street->getColor()) {
        case StreetColor::SC_BLUE: image_path = ":/Images/properties/blue_property.png"; break;
        case StreetColor::SC_GREEN: image_path = ":/Images/properties/green_property.png"; break;
        case StreetColor::SC_RED: image_path = ":/Images/properties/red_property.png"; break;
        case StreetColor::SC_LIGHTBLUE: image_path = ":/Images/properties/lightblue_property.png"; break;
        case StreetColor::SC_YELLOW: image_path = ":/Images/properties/yellow_property.png"; break;
        case StreetColor::SC_ORANGE: image_path = ":/Images/properties/orange_property.png"; break;
        case StreetColor::SC_BROWN: image_path = ":/Images/properties/brown_property.png"; break;
        case StreetColor::SC_PINK: image_path = ":/Images/properties/pink_property.png"; break;
        }

        item = new QGraphicsPixmapItem(QPixmap(image_path));

        scene->addItem(item);

    // ############################ DEED'S ELEMENTS #############################

        name_txt = new QGraphicsTextItem(street->NAME);
        name_txt->setPos(140, 110);
        name_txt->setFont(QFont("Times", 14, QFont::Bold));
        name_txt->setDefaultTextColor(Qt::white);
        scene->addItem(name_txt);

        rent_txt = new QGraphicsTextItem("RENT " + QString::number(street->RENT) + "$");
        rent_txt->setPos(140, 152);
        rent_txt->setFont(QFont("Times", 10));
        scene->addItem(rent_txt);

        explanation1_txt = new QGraphicsTextItem("Rent is doubled on owning all unimproved \n"
                                                               "                  sites in this group");
        explanation1_txt->setPos(80, 170);
        explanation1_txt->setFont(QFont("Times", 7));
        scene->addItem(explanation1_txt);

        QGraphicsPixmapItem *h1 = new QGraphicsPixmapItem(QPixmap(":/Images/Houses/h1.png").scaled(25, 25));
        h1->setPos(90, 220);
        scene->addItem(h1);

        QGraphicsTextItem *one_lvl_up_txt = new QGraphicsTextItem("with one house " + QString::number(street->WITH_ONE_HOUSE) + "$");
        one_lvl_up_txt->setPos(130, 215);
        one_lvl_up_txt->setFont(QFont("Times", 8));
        scene->addItem(one_lvl_up_txt);

        QGraphicsPixmapItem *h2 = new QGraphicsPixmapItem(QPixmap(":/Images/Houses/h2.png").scaled(25, 25));
        h2->setPos(90, 240);
        scene->addItem(h2);

        two_lvl_up_txt = new QGraphicsTextItem("with two house " + QString::number(street->WITH_TWO_HOUSE) + "$");
        two_lvl_up_txt->setPos(130, 245);
        two_lvl_up_txt->setFont(QFont("Times", 8));
        scene->addItem(two_lvl_up_txt);

        QGraphicsPixmapItem *h3 = new QGraphicsPixmapItem(QPixmap(":/Images/Houses/h3.png").scaled(25, 25));
        h3->setPos(90, 270);
        scene->addItem(h3);

        three_lvl_up_txt = new QGraphicsTextItem("with three house " + QString::number(street->WITH_THREE_HOUSE) + "$");
        three_lvl_up_txt->setPos(130, 275);
        three_lvl_up_txt->setFont(QFont("Times", 8));
        scene->addItem(three_lvl_up_txt);

        QGraphicsPixmapItem *h4 = new QGraphicsPixmapItem(QPixmap(":/Images/Houses/h4.png").scaled(25, 25));
        h4->setPos(90, 300);
        scene->addItem(h4);

        QGraphicsTextItem *four_lvl_up_txt = new QGraphicsTextItem("with four house " + QString::number(street->WITH_FOUR_HOUSE) + "$");
        four_lvl_up_txt->setPos(130, 305);
        four_lvl_up_txt->setFont(QFont("Times", 8));
        scene->addItem(four_lvl_up_txt);

        QGraphicsPixmapItem *hotel = new QGraphicsPixmapItem(QPixmap(":/Images/Houses/hotel.png").scaled(25, 25));
        hotel->setPos(90, 330);
        scene->addItem(hotel);

        five_lvl_up_txt = new QGraphicsTextItem("with hotel " + QString::number(street->WITH_HOTEL) + "$");
        five_lvl_up_txt->setPos(130, 335);
        five_lvl_up_txt->setFont(QFont("Times", 8));
        scene->addItem(five_lvl_up_txt);

        explanation2_txt = new QGraphicsTextItem("Construction " + QString::number(street->CONSTRUCTION) + "$ each");
        explanation2_txt->setPos(110, 370);
        explanation2_txt->setFont(QFont("Times", 8));
        scene->addItem(explanation2_txt);

        mortgage_txt = new QGraphicsTextItem("MORTGAGE " + QString::number(street->MORTGAGE) + "$");
        mortgage_txt->setPos(115, 390);
        mortgage_txt->setFont(QFont("Times", 10));
        scene->addItem(mortgage_txt);

        price_txt = new QGraphicsTextItem("For " + QString::number(street->PRICE) + "$");
        price_txt->setPos(305, 180);
        price_txt->setFont(QFont("Times", 12, QFont::Bold));
        scene->addItem(price_txt);


    }
    else if (typeid(*(property)) == typeid(Station)) {

        Station *station = dynamic_cast<Station *>(property);

        image_path = ":/Images/properties/station_property.png";
        item = new QGraphicsPixmapItem(QPixmap(image_path));
        scene->addItem(item);

        // ############################ DEED'S ELEMENTS #############################

        name_txt = new QGraphicsTextItem(station->NAME);
        name_txt->setPos(140, 110);
        name_txt->setFont(QFont("Times", 14, QFont::Bold));
        name_txt->setDefaultTextColor(Qt::white);
        scene->addItem(name_txt);

        rent_txt = new QGraphicsTextItem("RENT " + QString::number(station->PRICE) + "$");
        rent_txt->setPos(130, 160);
        rent_txt->setFont(QFont("Times", 14));
        scene->addItem(rent_txt);

        one_lvl_up_txt = new QGraphicsTextItem("2 stations " + QString::number(station->TWO_STATION) + "$");
        one_lvl_up_txt->setPos(115, 210);
        one_lvl_up_txt->setFont(QFont("Times", 14));
        scene->addItem(one_lvl_up_txt);

        two_lvl_up_txt = new QGraphicsTextItem("3 stations " + QString::number(station->THREE_STATION) + "$");
        two_lvl_up_txt->setPos(115, 260);
        two_lvl_up_txt->setFont(QFont("Times", 14));
        scene->addItem(two_lvl_up_txt);

        three_lvl_up_txt = new QGraphicsTextItem("4 stations " + QString::number(station->FOUR_STATION) + "$");
        three_lvl_up_txt->setPos(115, 310);
        three_lvl_up_txt->setFont(QFont("Times", 14));
        scene->addItem(three_lvl_up_txt);

        mortgage_txt = new QGraphicsTextItem("MORTGAGE " + QString::number(station->MORTGAGE) + "$");
        mortgage_txt->setPos(100, 380);
        mortgage_txt->setFont(QFont("Times", 14));
        scene->addItem(mortgage_txt);

        price_txt = new QGraphicsTextItem("For " + QString::number(station->PRICE) + "$");
        price_txt->setPos(305, 180);
        price_txt->setFont(QFont("Times", 12, QFont::Bold));
        scene->addItem(price_txt);

    }
    else if (typeid(*(property)) == typeid (Utility)) {
        Utility *utility = dynamic_cast<Utility *>(property);
        if(utility->space_num == 12)
            image_path = ":/Images/properties/electric_utility_deed.jpg";
        else if (utility->space_num == 28)
            image_path = ":/Images/properties/electric_utility_deed.jpg";

        item = new QGraphicsPixmapItem(QPixmap(image_path).scaled(400, 490));
        scene->addItem(item);

        price_txt = new QGraphicsTextItem("For " + QString::number(utility->PRICE) + "$");
        price_txt->setPos(305, 180);
        price_txt->setFont(QFont("Times", 12, QFont::Bold));
        scene->addItem(price_txt);
    }

// ######################### BUTTONS ##############################
    buy_btn = new QPushButton("Buy", this);
    buy_btn->setGeometry(305, 250, 80, 30);
    QColor col = QColor(Qt::green);
    if(col.isValid()) {
        QString qss = QString("background-color: %1").arg(col.name());
        buy_btn->setStyleSheet(qss);
        buy_btn->setFont(QFont("Georgia", 10, QFont::Bold));
    }



    auction_btn = new QPushButton("Auction", this);
    auction_btn->setGeometry(305, 330, 80, 30);
    col = QColor(Qt::red);
    if(col.isValid()) {
        QString qss = QString("background-color: %1").arg(col.name());
        auction_btn->setStyleSheet(qss);
        auction_btn->setFont(QFont("Georgia", 10, QFont::Bold));
    }

    connect(buy_btn, SIGNAL(clicked()), this, SLOT(buy()));
    connect(buy_btn, SIGNAL(clicked()), this, SLOT(Mclose()));
    connect(auction_btn, SIGNAL(clicked()), this, SLOT(Mclose()));
    connect(auction_btn, SIGNAL(clicked()), this, SLOT(auction()));
}

void Deed::setPlayer(Player *_player)
{
    player = _player;

    if (player->getMoney() < property->PRICE)
        buy_btn->setDisabled(true);
}

void Deed::Mclose()
{
    container->Mclose();
}

void Deed::buy()
{
    Monopoly::instance()->buyPropertyForPlayer(player, property, property->PRICE);
    Monopoly::instance()->space_done();
}

void Deed::auction()
{
    Monopoly::instance()->auction(property);
    container->Mclose();
}
