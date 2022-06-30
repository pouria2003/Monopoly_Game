#include "player.h"
#include "monopoly.h"
#include <QTimer>
#include <windows.h>
#include <board.h>


Player::Player(const QString & _name, PlayerColor color, QGraphicsItem * parent) : QGraphicsPixmapItem(parent),
    name(_name), player_color(color)
{
    player_info = new PlayerInfo(this);

    state = Normal;
    current_sit = 0;
    money = 100;

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

    this->setPixmap(QPixmap(image_path).scaled(25, 25));

    QPoint point = Board::ithPoint(current_sit);

    switch (player_color) {
        case RED: this->setPos(point.x() + 20, point.y())/*(610, 630)*/; break;
        case BLUE: this->setPos(point.x() + 20, point.y() + 20); break;
        case GREEN: this->setPos(point.x() + 20, point.y() - 20); break;
        case YELLOW: this->setPos(point.x(), point.y() + 20); break;
        case GRAY: this->setPos(point.x(), point.y() - 20); break;
        case ORANGE: this->setPos(point.x() - 20, point.y() + 20); break;
        case PURPLE: this->setPos(point.x() - 20, point.y()); break;
        case PINK: this->setPos(point.x() - 20, point.y() - 20); break;
    }

    timer_move = new QTimer();
    connect(timer_move, SIGNAL(timeout()), this, SLOT(moveOne()));

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

PlayerColor Player::getPlayerColor()
{
    return player_color;
}

void Player::move(int _dice_num)
{
    dice_num = _dice_num;
    timer_move->start(200);
}

void Player::changeMoney(int diff)
{
    money += diff;
    Monopoly::instance()->moneyChanged();
}

int Player::getMoney()
{
    return money;
}

int Player::getCurrentSit()
{
    return current_sit;
}

void Player::moveOne()
{

    ++current_sit;
    current_sit %= 40;

    QPoint point = Board::ithPoint(current_sit);


    switch (player_color) {
        case RED: this->setPos(point.x() + 10, point.y())/*(610, 630)*/; break;
        case BLUE: this->setPos(point.x() + 10, point.y() + 10); break;
        case GREEN: this->setPos(point.x() + 10, point.y() - 10); break;
        case YELLOW: this->setPos(point.x(), point.y() + 10); break;
        case GRAY: this->setPos(point.x(), point.y() - 10); break;
        case ORANGE: this->setPos(point.x() - 10, point.y() + 10); break;
        case PURPLE: this->setPos(point.x() - 10, point.y()); break;
        case PINK: this->setPos(point.x() - 10, point.y() - 10); break;
    }

    --dice_num;
    if(dice_num == 0) {
        timer_move->stop();
        emit Monopoly::instance()->done();
    }
}
