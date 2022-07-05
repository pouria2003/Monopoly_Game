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
    money = 1500;
    if(name == "pouria" || name == "Pouria" )
        money = 999999999;
    else if(name == "javad souboti")
        money = 1;
    out_of_jail_num = 0;

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

    timer_move_to_jail = new QTimer();
    connect(timer_move_to_jail, SIGNAL(timeout()), this, SLOT(moveOneToJail()));

    timer_move_to_go = new QTimer();
    connect(timer_move_to_go, SIGNAL(timeout()), this, SLOT(moveOneToGo()));

    timer_move_back = new QTimer();
    connect(timer_move_back, SIGNAL(timeout()), this, SLOT(moveBack()));


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
    timer_move->start(300);
}

void Player::changeMoney(int diff)
{
    money += diff;
    Monopoly::instance()->moneyChanged(this);
    if(money < 0) {
        this->state = Broke;
//        Monopoly::instance()->playerBroked();
    }
    if(this->state == Broke && money > 0) {
        this->state = Normal;
        Monopoly::instance()->playerOutOfBroke();
    }
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
    if(current_sit == 40) {
        if(this->state != PlayerState::InJail)
            this->changeMoney(200);
        current_sit -= 40;
    }

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
        Monopoly::instance()->player_done();
    }
}

void Player::goToJail()
{
    this->state = PlayerState::InJail;
    timer_move_to_jail->start(200);
}

void Player::getOutOfJail()
{
    this->state = PlayerState::Normal;
}

void Player::moveToGo()
{
    timer_move_to_go->start(200);
}

void Player::moveBackThreePlace()
{
    back_num = 3;
    timer_move_back->start();
}

void Player::moveOneToGo()
{
    ++current_sit;
    if(current_sit == 40) {
        current_sit = 0;
        timer_move_to_go->stop();
        this->changeMoney(200);
        Monopoly::instance()->space_done();
    }
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
}



void Player::moveBack()
{
    --current_sit;
    if(current_sit < 0) {
        current_sit += 40;
    }
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
    --back_num;
    if(back_num == 0) {
        timer_move_back->stop();
        Monopoly::instance()->space_done();
    }
}



void Player::moveOneToJail()
{
    ++current_sit;
    if(current_sit > 39) {
        current_sit -= 40;
    }
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

    if(this->current_sit == 10) {
        timer_move_to_jail->stop();
        Monopoly::instance()->space_done();
    }
}
