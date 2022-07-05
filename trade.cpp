#include "trade.h"
#include "QGraphicsPixmapItem"
#include "tradecontainer.h"

Trade::Trade(TradeContainer *_container, QWidget * parent) : QGraphicsView(parent), container(_container)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene(this);
    this->setScene(scene);

    my_money_slider = new QSlider(Qt::Orientation::Horizontal, this);
    my_money_lbl = new QLabel(this);

    other_money_slider = new QSlider(Qt::Orientation::Horizontal, this);
    other_money_lbl = new QLabel(this);

    connect(my_money_slider, SIGNAL(valueChanged(int)), my_money_lbl, SLOT(setNum(int)));
    connect(other_money_slider, SIGNAL(valueChanged(int)), other_money_lbl, SLOT(setNum(int)));

    accept_btn = new QPushButton(this);
    reject_btn = new QPushButton(this);

    connect(reject_btn, SIGNAL(clicked()), container, SLOT(Mhide()));
    connect(accept_btn, SIGNAL(clicked()), this, SLOT(trade()));

    bg = new QGraphicsPixmapItem(QPixmap(":/Images/trade_bg.png").scaled(800, 600));
    scene->addItem(bg);
}


void Trade::setTrade(QVector<int> * _my_sites, QVector<int> *_other_sites, int my_money, int other_money)
{
    my_sites = _my_sites; other_sites = _other_sites;

    my_money_slider->setMinimum(0);
    my_money_slider->setMaximum(my_money);
    my_money_slider->setGeometry(100, 530, 200, 20);
    my_money_lbl->setGeometry(180, 550, 40, 20);

    other_money_slider->setMinimum(0);
    other_money_slider->setMaximum(other_money);
    other_money_slider->setGeometry(500, 530, 200, 20);
    other_money_lbl->setGeometry(580, 550, 40, 20);

    accept_btn->setText("Accept");
    accept_btn->setGeometry(720, 520, 60, 30);

    reject_btn->setText("Reject");
    reject_btn->setGeometry(420, 520, 60, 30);

    QColor col = QColor(Qt::green);
    if(col.isValid()) {
       QString qss = QString("background-color: %1").arg(col.name());
       accept_btn->setStyleSheet(qss);
       accept_btn->setFont(QFont("Georgia", 10, QFont::Bold));
    }

    col = QColor(Qt::red);
    if(col.isValid()) {
       QString qss = QString("background-color: %1").arg(col.name());
       reject_btn->setStyleSheet(qss);
       reject_btn->setFont(QFont("Georgia", 10, QFont::Bold));
    }

    for(int i = 0; i < my_sites->size(); ++i) {
        my_deeds.push_back(new QGraphicsPixmapItem(
                               QPixmap(":/Images/deed/deed_" + QString::number(my_sites->value(i)) +
                                       ( (my_sites->value(i) == 12 || (my_sites->value(i) == 28 )) ? ".jpg" : ".png") ).scaled(80, 110)));
        my_btns[my_sites->value(i)] = new QCheckBox(this);
        my_deeds.value(i)->setPos(myDeedPoint(i));
        my_btns[my_sites->value(i)]->setGeometry(myDeedPoint(i).x() + 35, myDeedPoint(i).y() + 115, 10, 10);
        scene->addItem(my_deeds[i]);
    }

    for(int i = 0; i < other_sites->size(); ++i) {
        other_deeds.push_back(new QGraphicsPixmapItem(
                               QPixmap(":/Images/deed/deed_" + QString::number(my_sites->value(i)) +
                                       ( (my_sites->value(i) == 12 || (my_sites->value(i) == 28 )) ? ".jpg" : ".png") ).scaled(80, 110)));
        other_btns[other_sites->value(i)] = new QCheckBox(this);
        other_deeds.value(i)->setPos(otherDeedPoint(i));
        other_btns[other_sites->value(i)]->setGeometry(otherDeedPoint(i).x() + 35, otherDeedPoint(i).y() + 115, 10, 10);
        scene->addItem(other_deeds[i]);
    }

}

QPoint Trade::myDeedPoint(int ith)
{
    QPoint point;
    point.setX((ith % 4) * 90 + 30);
    point.setY((ith / 4) * 125 + 130);
    return point;
}

QPoint Trade::otherDeedPoint(int ith)
{
    QPoint point;
    point.setX((ith % 4) * 90 + 430);
    point.setY((ith / 4) * 125 + 130);
    return point;

}

void Trade::Mhide()
{
    for(int i = 0; i < my_deeds.size(); ++i) {
        delete my_deeds.value(i);
    }
    for(int i = 0; i < other_deeds.size(); ++i) {
        delete other_deeds.value(i);
    }

    for(int i = 0; i < 40; ++i) {
        if(my_btns.contains(i)) {
            delete my_btns[i];
        }
        else if(other_btns.contains(i)) {
            delete other_btns[i];
        }
    }

    my_btns.clear(); other_btns.clear();
    my_deeds.clear(); other_deeds.clear();

    this->hide();

}

void Trade::trade()
{
    QVector<int> *deedsYouGive = new QVector<int>;
    QVector<int> *deedsYouGet = new QVector<int>;

    for(int i = 0; i < 40; ++i) {
        if(my_btns.contains(i) && my_btns[i]->isChecked()) {
            deedsYouGive->push_back(i);
        }
        else if(other_btns.contains(i) && other_btns[i]->isChecked()) {
            deedsYouGet->push_back(i);
        }
    }

    container->doTrade(deedsYouGive, deedsYouGet, my_money_slider->value(), other_money_slider->value());
}
