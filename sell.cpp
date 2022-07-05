#include "sell.h"
#include <QGraphicsPixmapItem>
#include <QButtonGroup>
#include "monopoly.h"
#include "build.h"

Sell::Sell(QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene;
    this->setScene(scene);

    bg = new QGraphicsPixmapItem(QPixmap(":/Images/build_bg.png"));
    scene->addItem(bg);

    button_group = new QButtonGroup(this);
    connect(button_group, SIGNAL(idClicked(int)), Monopoly::instance(), SLOT(sellSit(int)));
}

void Sell::setSell(QVector<int> *_sites)
{
    sites = _sites;
    QColor col;

    for(int i = 0, j = 0; i < sites->size(); ++i) {

        if(sites->value(i) == -1)
            continue;

        deeds.push_back(new QGraphicsPixmapItem(QPixmap(":/Images/deed/deed_" +
                                                        QString::number(sites->value(i)) + ".png").scaled(120, 150)));

        deeds[j]->setPos(Build::ithDeedPoint(j));
        scene->addItem(deeds[j]);

        buttons.push_back(new QPushButton("Sell", this));

        buttons[j]->setGeometry(Build::ithDeedPoint(j).x() + 10, Build::ithDeedPoint(j).y() + 160 , 100, 30);

        col = QColor(Qt::red);
        if(col.isValid()) {
           QString qss = QString("background-color: %1").arg(col.name());
           buttons[j]->setStyleSheet(qss);
           buttons[j]->setFont(QFont("Georgia", 10, QFont::Bold));
        }

        button_group->addButton(buttons[j], sites->value(i));

        ++j;
    }

    this->refresh(0);

    connect(button_group, SIGNAL(idClicked(int)), this, SLOT(refresh(int)));
}


void Sell::refresh(int)
{
    for(int i = 0; i < buttons.size(); ++i) {
        buttons[i]->setEnabled(Monopoly::instance()->isSelable(button_group->id(buttons[i])));
    }
}

void Sell::Mhide()
{
    for(int i = 0; i < deeds.size(); ++i) {
        scene->removeItem(deeds[i]);
        delete deeds[i];
        button_group->removeButton(buttons[i]);
        delete buttons[i];
    }
    deeds.clear();
    buttons.clear();
    delete sites;
}
