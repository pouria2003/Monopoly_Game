#include "deedcontainer.h"
#include "player.h"
#include "monopoly.h"

DeedContainer::DeedContainer(PropertySpace *property, QWidget *parent)
    : QWidget{parent}
{

    deed = new Deed(property, this);
    this->setGeometry(200, 100, 410, 500);

    player_name_lbl = new QLabel(this);
    player_name_lbl->setFont(QFont("Times", 12, QFont::Bold));
    player_name_lbl->setGeometry(7, -36, 100, 100);


    this->hide();
}

void DeedContainer::Mshow(Player *player)
{
    player_name_lbl->setText(player->getName());
    deed->setPlayer(player);
    Monopoly::instance()->disableButtons();
    this->show();
}
