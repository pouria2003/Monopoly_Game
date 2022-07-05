#ifndef TRADE_H
#define TRADE_H

#include <QGraphicsView>
#include <QPushButton>
#include <QCheckBox>
#include <QHash>
#include <QLabel>
#include <QSlider>

class TradeContainer;

class Trade : public QGraphicsView
{
    Q_OBJECT
public:
    Trade(TradeContainer *container, QWidget * = nullptr);
    void setTrade(QVector<int> *my_sites, QVector<int> *other_sites, int my_money, int other_money);

private:
    static QPoint myDeedPoint(int ith);
    static QPoint otherDeedPoint(int ith);

private:
    TradeContainer *container;
    QGraphicsScene *scene;

    QVector<QGraphicsPixmapItem *> my_deeds;
    QVector<QGraphicsPixmapItem *> other_deeds;

    QHash<int, QCheckBox *> my_btns;
    QHash<int, QCheckBox *> other_btns;

    QGraphicsPixmapItem *bg;

    QVector<int> *my_sites;
    QVector<int> *other_sites;

    QSlider *my_money_slider;
    QLabel *my_money_lbl;

    QSlider *other_money_slider;
    QLabel *other_money_lbl;

    QPushButton *accept_btn;
    QPushButton *reject_btn;

public slots:
    void Mhide();
    void trade();
};

#endif // TRADE_H
