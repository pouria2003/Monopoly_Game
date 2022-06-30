#include "deed.h"
#include "propertyspace.h"
#include <QGraphicsTextItem>
#include "street.h"
#include "station.h"
#include "player.h"
#include "monopoly.h"
#include <typeinfo>

Deed::Deed(PropertySpace *_property, QWidget *p) : QGraphicsView(p), property(_property)
{


    scene = new QGraphicsScene;

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
        QGraphicsTextItem *name_txt = new QGraphicsTextItem(street->NAME);
        name_txt->setPos(140, 110);
        name_txt->setFont(QFont("Times", 14, QFont::Bold));
        name_txt->setDefaultTextColor(Qt::white);
        scene->addItem(name_txt);

        QGraphicsTextItem *rent_txt = new QGraphicsTextItem("RENT " + QString::number(street->RENT) + "$");
        rent_txt->setPos(140, 152);
        rent_txt->setFont(QFont("Times", 10));
        scene->addItem(rent_txt);

        QGraphicsTextItem *explain_txt = new QGraphicsTextItem("Rent is doubled on owning all unimproved \n"
                                                               "                  sites in this group");
        explain_txt->setPos(80, 170);
        explain_txt->setFont(QFont("Times", 7));
        scene->addItem(explain_txt);

        QGraphicsPixmapItem *h1 = new QGraphicsPixmapItem(QPixmap(":/Images/Houses/h1.png").scaled(25, 25));
        h1->setPos(90, 220);
        scene->addItem(h1);

        QGraphicsTextItem *h1_txt = new QGraphicsTextItem("with one house " + QString::number(street->WITH_ONE_HOUSE) + "$");
        h1_txt->setPos(130, 215);
        h1_txt->setFont(QFont("Times", 8));
        scene->addItem(h1_txt);

        QGraphicsPixmapItem *h2 = new QGraphicsPixmapItem(QPixmap(":/Images/Houses/h2.png").scaled(25, 25));
        h2->setPos(90, 240);
        scene->addItem(h2);

        QGraphicsTextItem *h2_txt = new QGraphicsTextItem("with two house " + QString::number(street->WITH_TWO_HOUSE) + "$");
        h2_txt->setPos(130, 245);
        h2_txt->setFont(QFont("Times", 8));
        scene->addItem(h2_txt);

        QGraphicsPixmapItem *h3 = new QGraphicsPixmapItem(QPixmap(":/Images/Houses/h3.png").scaled(25, 25));
        h3->setPos(90, 270);
        scene->addItem(h3);

        QGraphicsTextItem *h3_txt = new QGraphicsTextItem("with three house " + QString::number(street->WITH_THREE_HOUSE) + "$");
        h3_txt->setPos(130, 275);
        h3_txt->setFont(QFont("Times", 8));
        scene->addItem(h3_txt);

        QGraphicsPixmapItem *h4 = new QGraphicsPixmapItem(QPixmap(":/Images/Houses/h4.png").scaled(25, 25));
        h4->setPos(90, 300);
        scene->addItem(h4);

        QGraphicsTextItem *h4_txt = new QGraphicsTextItem("with four house " + QString::number(street->WITH_FOUR_HOUSE) + "$");
        h4_txt->setPos(130, 305);
        h4_txt->setFont(QFont("Times", 8));
        scene->addItem(h4_txt);

        QGraphicsPixmapItem *hotel = new QGraphicsPixmapItem(QPixmap(":/Images/Houses/hotel.png").scaled(25, 25));
        hotel->setPos(90, 330);
        scene->addItem(hotel);

        QGraphicsTextItem *hotel_txt = new QGraphicsTextItem("with hotel " + QString::number(street->WITH_HOTEL) + "$");
        hotel_txt->setPos(130, 335);
        hotel_txt->setFont(QFont("Times", 8));
        scene->addItem(hotel_txt);

        QGraphicsTextItem *construction_txt = new QGraphicsTextItem("Construction " + QString::number(street->CONSTRUCTION) + "$ each");
        construction_txt->setPos(110, 370);
        construction_txt->setFont(QFont("Times", 8));
        scene->addItem(construction_txt);

        QGraphicsTextItem *mortgage_txt = new QGraphicsTextItem("MORTGAGE " + QString::number(street->MORTGAGE) + "$");
        mortgage_txt->setPos(115, 390);
        mortgage_txt->setFont(QFont("Times", 10));
        scene->addItem(mortgage_txt);

    }
    else if (typeid(*(property)) == typeid(Station)) {
        image_path = ":/Images/properties/station_property.png";
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

    connect(buy_btn, SIGNAL(clicked()), this, SLOT(close()));
    connect(auction_btn, SIGNAL(clicked()), this, SLOT(close()));

}

void Deed::setPlayer(Player *_player)
{
    player = _player;

    if (player->getMoney() < property->PRICE)
        buy_btn->setDisabled(true);
}

void Deed::Mclose()
{
    qDebug() << " in MCLose ";
    Monopoly::instance()->enableButtons();
    this->close();
}
