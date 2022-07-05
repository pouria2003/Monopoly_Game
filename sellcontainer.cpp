#include "sellcontainer.h"
#include "sell.h"
#include <QDebug>
#include "monopoly.h"

SellContainer::SellContainer(QWidget *parent)
    : QWidget{parent}
{
    this->setGeometry(200, 100, 780, 525);
    sell = new Sell(this);

    finish_button = new QPushButton("Finish", this);
    finish_button->setGeometry(690, 10, 80, 30);

    connect(finish_button, SIGNAL(clicked()), this, SLOT(Mhide()));
    connect(finish_button, SIGNAL(clicked()), Monopoly::instance(), SLOT(enableOtherButtons()));
    this->hide();
}

void SellContainer::createSell(QVector<int> *sites)
{
    sell->setSell(sites);
    this->show();
}

void SellContainer::Mhide()
{
    sell->Mhide();
    this->hide();
}
