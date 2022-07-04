 #include "buildcontainer.h"
#include "build.h"
#include <iostream>

BuildContainer::BuildContainer(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(200, 100, 780, 525);
    build = new Build(this);

    finish_button = new QPushButton("Finish", this);
    finish_button->setGeometry(690, 10, 80, 30);

    connect(finish_button, SIGNAL(clicked()), this, SLOT(Mhide()));
    this->hide();
}

void BuildContainer::createBuild(QVector<int> *sites)
{
    build->setBuild(sites);
    this->show();
}

void BuildContainer::Mhide()
{
    build->Mhide();
    this->hide();
}
