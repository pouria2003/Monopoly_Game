#ifndef MORTGAGE_H
#define MORTGAGE_H

#include <QGraphicsView>
#include <QPushButton>

class Mortgage : public QGraphicsView
{
    Q_OBJECT
public:
    Mortgage(QWidget * = nullptr);
    void setMortgage(QVector<int> *sites);

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

#endif // MORTGAGE_H
