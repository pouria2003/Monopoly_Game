#include "playerinfo.h"
#include "player.h"
#include <stdexcept>
#include <QFont>

PlayerInfo::PlayerInfo(Player *_player, QGraphicsItem * parent) : QGraphicsPixmapItem(parent)
{
    if(_player == nullptr) {
        throw std::invalid_argument("player passed to player info cannot be null");
    }
    player = _player;
    setPixmap(QPixmap(":/Images/Light wooden background_.jfif").scaled(140, 50));

    name_txt = new QGraphicsTextItem(this);

    name_txt->setPlainText(player->getName());

    name_txt->setFont(QFont("times", 14));
    name_txt->setDefaultTextColor(Qt::black);
    name_txt->setPos(0, 0);

    money_txt = new QGraphicsTextItem(this);

    money_txt->setPlainText(QString::number(money) + "$");
    money_txt->setFont(QFont("Times", 14, QFont::Bold));
    money_txt->setDefaultTextColor(Qt::darkGreen);
    money_txt->setPos(0, 20);



}

int PlayerInfo::getMoney()
{
    return money;
}

void PlayerInfo::alterMoney(int mon)
{
    /// if(money + mon < 0)
    money += mon;
}
