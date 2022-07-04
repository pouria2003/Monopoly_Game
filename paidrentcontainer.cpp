#include "paidrentcontainer.h"
#include "paidrent.h"

PaidRentContainer::PaidRentContainer(QWidget *parent)
    : QWidget{parent}
{
    paid_rent = new PaidRent(this);
    this->setGeometry(210, 150, 389, 395);
    this->hide();
}

void PaidRentContainer::Mshow(Player *payer, Player *payee, int rent)
{
    paid_rent->setPaidRent(payer, payee, rent);
    this->show();
}
