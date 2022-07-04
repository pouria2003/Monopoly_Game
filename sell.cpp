#include "sell.h"
#include <QGraphicsPixmapItem>
#include <QButtonGroup>
#include "monopoly.h"

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

        deeds[j]->setPos(ithDeedPoint(j));
        scene->addItem(deeds[j]);

        buttons.push_back(new QPushButton("Sell", this));

        buttons[j]->setGeometry(ithDeedPoint(j).x() + 10, ithDeedPoint(j).y() + 160 , 100, 30);

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

QPoint Sell::ithDeedPoint(int ith)
{
    switch(ith) {
    case 0: return QPoint(30, 100);
    case 1: return QPoint(170, 100);
    case 2: return QPoint(310, 100);
    case 3: return QPoint(450, 100);
    case 4: return QPoint(590, 100);
    case 5: return QPoint(30, 300);
    case 6: return QPoint(170, 300);
    case 7: return QPoint(310, 300);
    case 8: return QPoint(450, 300);
    case 9: return QPoint(590, 300);
    default : return QPoint(-500, -500);
    }
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
