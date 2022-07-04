#include "injail.h"
#include "player.h"

InJail::InJail(QWidget *parent)
    : QWidget{parent}
{
    QWidget::setWindowFlags(Qt::Window);

    use_card = new QPushButton("Use card", this);

    role_dice = new QPushButton("Role dice", this);

    pay = new QPushButton("Pay 100$", this);

    connect(use_card, SIGNAL(clicked()), this, SLOT(hide()));
    connect(role_dice, SIGNAL(clicked()), this, SLOT(hide()));
    connect(pay, SIGNAL(clicked()), this, SLOT(hide()));

    layout = new QHBoxLayout(this);
    layout->addWidget(use_card);
    layout->addWidget(role_dice);
    layout->addWidget(pay);

    this->setLayout(layout);

}

void InJail::Mshow(Player *player) {
    if(player->out_of_jail_num == 0)
        use_card->setEnabled(false);

    if(player->getMoney() < 100)
        pay->setEnabled(false);

    this->show();
}
