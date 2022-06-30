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

    money = player->getMoney();

    setPixmap(QPixmap(":/Images/p_info_bg.png").scaled(200, 70));

    name_txt = new QGraphicsTextItem(this);

    name_txt->setPlainText(player->getName());

    name_txt->setFont(QFont("times", 14, QFont::Bold));
    name_txt->setDefaultTextColor(Qt::darkCyan);
    name_txt->setPos(40, 5);


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

    player_color = new QGraphicsPixmapItem(QPixmap(image_path).scaled(20, 20), this);
    player_color->setPos(145, 5);

}
