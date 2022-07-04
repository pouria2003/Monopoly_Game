#include "paidrent.h"
#include "player.h"

PaidRent::PaidRent(QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene;

    this->setScene(scene);

    scene->addItem(new QGraphicsPixmapItem(QPixmap(":/Images/properties/paid_rent_template.png")));

    payer_pixmap = new QGraphicsPixmapItem;
    payer_pixmap->setPos(70, 230);
    scene->addItem(payer_pixmap);

    payee_pixmap = new QGraphicsPixmapItem;
    payee_pixmap->setPos(270, 230);
    scene->addItem(payee_pixmap);

    payer_txt = new QGraphicsTextItem;
    payer_txt->setPos(70, 290);
    payer_txt->setFont(QFont("Times", 14, QFont::Bold));
    scene->addItem(payer_txt);

    payee_txt = new QGraphicsTextItem;
    payee_txt->setPos(270, 290);
    payee_txt->setFont(QFont("Times", 14, QFont::Bold));
    scene->addItem(payee_txt);

    money_txt = new QGraphicsTextItem;
    money_txt->setPos(160, 110);
    money_txt->setFont(QFont("Times", 18, QFont::Bold));
    scene->addItem(money_txt);
}

void PaidRent::setPaidRent(Player *payer, Player *payee, int rent)
{
//    qDebug() << payer->getPlayerColor() << payee->getPlayerColor();

    QString player_image_path;
    switch (payer->getPlayerColor()) {
        case RED: player_image_path = ":/Images/red_player.png"; break;
        case BLUE: player_image_path = ":/Images/blue_player.png"; break;
        case GREEN: player_image_path = ":/Images/green_player.png"; break;
        case YELLOW: player_image_path = ":/Images/yellow_player.png"; break;
        case GRAY: player_image_path = ":/Images/gray_player.png"; break;
        case ORANGE: player_image_path = ":/Images/orange_player.png"; break;
        case PURPLE: player_image_path = ":/Images/purple_player.png"; break;
        case PINK: player_image_path = ":/Images/pink_player.png"; break;
    }
    payer_pixmap->setPixmap(QPixmap(player_image_path).scaled(50, 50));

    switch (payee->getPlayerColor()) {
        case RED: player_image_path = ":/Images/red_player.png"; break;
        case BLUE: player_image_path = ":/Images/blue_player.png"; break;
        case GREEN: player_image_path = ":/Images/green_player.png"; break;
        case YELLOW: player_image_path = ":/Images/yellow_player.png"; break;
        case GRAY: player_image_path = ":/Images/gray_player.png"; break;
        case ORANGE: player_image_path = ":/Images/orange_player.png"; break;
        case PURPLE: player_image_path = ":/Images/purple_player.png"; break;
        case PINK: player_image_path = ":/Images/pink_player.png"; break;
    }
    payee_pixmap->setPixmap(QPixmap(player_image_path).scaled(50, 50));

    payer_txt->setPlainText(payer->getName());
    payee_txt->setPlainText(payee->getName());

    money_txt->setPlainText(QString::number(rent) + "$");
}

























