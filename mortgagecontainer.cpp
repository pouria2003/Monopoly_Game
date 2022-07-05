#include "mortgagecontainer.h"
#include "monopoly.h"

MortgageContainer::MortgageContainer(QWidget *parent)
    : QWidget{parent}
{
    this->setGeometry(200, 100, 780, 525);
    mortgage = new Mortgage(this);

    finish_button = new QPushButton("Finish", this);
    finish_button->setGeometry(690, 10, 80, 30);

    connect(finish_button, SIGNAL(clicked()), this, SLOT(Mhide()));
    connect(finish_button, SIGNAL(clicked()), Monopoly::instance(), SLOT(enableOtherButtons()));

    this->hide();
}

void MortgageContainer::createMortgage(QVector<int> *sites)
{
    mortgage->setMortgage(sites);
    this->show();
}

void MortgageContainer::Mhide()
{
    mortgage->Mhide();
    this->hide();
}
