#include "player.h"


Player::Player(const QString & _name, PlayerColor color, QGraphicsItem * parent) : QGraphicsPixmapItem(parent), name(_name)
{
    player_info = new PlayerInfo(this);

    state = NotStarted;

    QString image_path;
    switch (color) {
        case RED: image_path = ":/Images/red_player.png"; break;
        case BLUE: image_path = ":/Images/blue_player.png"; break;
        case GREEN: image_path = ":/Images/green_player.png"; break;
        case YELLOW: image_path = ":/Images/yellow_player.png"; break;
        case GRAY: image_path = ":/Images/gray_player.png"; break;
        case ORANGE: image_path = ":/Images/orange_player.png"; break;
        case PURPLE: image_path = ":/Images/purple_player.png"; break;
        case PINK: image_path = ":/Images/pink_player.png"; break;
    }
    this->setPixmap(QPixmap(image_path).scaled(50, 50));
    this->setPos(500, 500);
}

QString Player::getName()
{
    return name;
}

void Player::setState(PlayerState _state)
{
    state = _state;
}

Player::PlayerState Player::getState()
{
    return this->state;
}
