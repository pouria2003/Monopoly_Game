#include "mortgage.h"
#include <QGraphicsPixmapItem>
#include <QButtonGroup>
#include "monopoly.h"
#include "build.h"

Mortgage::Mortgage(QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene;
    this->setScene(scene);

    bg = new QGraphicsPixmapItem(QPixmap(":/Images/Mortgage_bg.png"));
    scene->addItem(bg);

    button_group = new QButtonGroup(this);
    connect(button_group, SIGNAL(idClicked(int)), Monopoly::instance(), SLOT(mortgageSit(int)));
}

void Mortgage::setMortgage(QVector<int> *_sites)
{
    sites = _sites;
    QColor col;

    for(int i = 0; i < sites->size(); ++i) {

        if(sites->value(i) == -1){
            qDebug() << "##########################/n#####################/n#################/n/a/a";
        }
//            continue;
        qDebug() << "in setBuild space shomare : " << sites->value(i);
        deeds.push_back(new QGraphicsPixmapItem(QPixmap(":/Images/deed/deed_" +
                                                        QString::number(sites->value(i)) + ".png").scaled(120, 150)));


        deeds[i]->setPos(Build::ithDeedPoint(i));
        scene->addItem(deeds[i]);

        buttons.push_back(new QPushButton(this));

        buttons[i]->setGeometry(Build::ithDeedPoint(i).x() + 10, Build::ithDeedPoint(i).y() + 160 , 100, 30);

        button_group->addButton(buttons[i], sites->value(i));

    }

    this->refresh(0);

    connect(button_group, SIGNAL(idClicked(int)), this, SLOT(refresh(int)));
}

void Mortgage::refresh(int just_to_match_signal)
{
     QColor col;
    for(int i = 0; i < buttons.size(); ++i) {
        if(Monopoly::instance()->isMortgageable(button_group->id(buttons[i]))) {
            buttons[i]->setText("Mortgage");
            col = Qt::red;
        }
        else {
            buttons[i]->setText("UnMortgage");
            col = Qt::green;
        }
        if(col.isValid()) {
            QString qss = QString("background-color: %1").arg(col.name());
            buttons[i]->setStyleSheet(qss);
            buttons[i]->setFont(QFont("Georgia", 10, QFont::Bold));
         }
    }
}

void Mortgage::Mhide()
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
