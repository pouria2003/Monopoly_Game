#include "build.h"
#include <QGraphicsPixmapItem>
#include "monopoly.h"

Build::Build(QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene;
    this->setScene(scene);

    bg = new QGraphicsPixmapItem(QPixmap(":/Images/build_bg.png"));
    scene->addItem(bg);

    button_group = new QButtonGroup(this);
    connect(button_group, SIGNAL(idClicked(int)), Monopoly::instance(), SLOT(buildSit(int)));
}

void Build::setBuild(QVector<int> *_sites)
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


        deeds[i]->setPos(ithDeedPoint(i));
        scene->addItem(deeds[i]);

        buttons.push_back(new QPushButton("Build", this));

        buttons[i]->setGeometry(ithDeedPoint(i).x() + 10, ithDeedPoint(i).y() + 160 , 100, 30);

        col = QColor(Qt::green);
        if(col.isValid()) {
           QString qss = QString("background-color: %1").arg(col.name());
           buttons[i]->setStyleSheet(qss);
           buttons[i]->setFont(QFont("Georgia", 10, QFont::Bold));
        }

        button_group->addButton(buttons[i], sites->value(i));

    }

    this->refresh(0);

    connect(button_group, SIGNAL(idClicked(int)), this, SLOT(refresh(int)));

}

QPoint Build::ithDeedPoint(int ith)
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
    case 10: return QPoint(30, 500);
    case 11: return QPoint(170, 500);
    case 12: return QPoint(310, 500);
    case 13: return QPoint(450, 500);
    case 14: return QPoint(30, 700);
    case 15: return QPoint(170, 700);
    case 16: return QPoint(310, 700);
    case 17: return QPoint(450, 700);
    }
}

void Build::refresh(int just_to_match_signal)
{
    for(int i = 0; i < buttons.size(); ++i) {
        qDebug() << "in refresh for button " << i << " : id : " <<  button_group->id(buttons[i]);
//        if(!Monopoly::instance()->isUpadatable(button_group->id(buttons[i]))) {
//            qDebug() << "button bayad disable she";
//            buttons[i]->setEnabled(false);
//        }
        buttons[i]->setEnabled(Monopoly::instance()->isUpadatable(button_group->id(buttons[i])));

    }
}

void Build::Mhide()
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

