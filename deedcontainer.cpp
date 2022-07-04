#include "deedcontainer.h"
#include "player.h"
#include "monopoly.h"

DeedContainer::DeedContainer(QWidget *parent)
    : QWidget{parent}
{

    deed = new Deed(this, this);
    this->setGeometry(200, 70, 410, 500);

    player_name_lbl = new QLabel(this);
    player_name_lbl->setFont(QFont("Times", 12, QFont::Bold));
    player_name_lbl->setGeometry(7, -36, 100, 100);

    this->hide();
}

void DeedContainer::Mshow(PropertySpace *property, Player *player)
{
    player_name_lbl->setText(player->getName());
//    deed->setPlayer(player);
    deed->setDeed(property, player);
//    Monopoly::instance()->disableTassButtons();
    this->show();
}

DeedContainer::~DeedContainer()
{
    delete deed;
    delete player_name_lbl;
}

void DeedContainer::Mclose()
{
    this->hide();
}
