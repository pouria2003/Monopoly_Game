#ifndef SELL_H
#define SELL_H


#include <QGraphicsView>
#include <QPushButton>

class Sell : public QGraphicsView
{
    Q_OBJECT
public:
    Sell(QWidget * = nullptr);
    void setSell(QVector<int> *sites);
    QPoint ithDeedPoint(int);

private:
    QGraphicsScene *scene;
    QVector<QGraphicsPixmapItem *> deeds;
    QVector<QPushButton *> buttons;
    QButtonGroup *button_group;
    QGraphicsPixmapItem *bg;
    QVector<int> *sites;

public slots:
    void refresh(int);
    void Mhide();
};

#endif // SELL_H
