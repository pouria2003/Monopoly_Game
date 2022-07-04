#ifndef BUILD_H
#define BUILD_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVector>
#include <QButtonGroup>
#include <QPushButton>


class Build : public QGraphicsView
{
    Q_OBJECT
public:
    Build(QWidget * = nullptr);
    void setBuild(QVector<int> *sites);
    QPoint ithDeedPoint(int ith);

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



#endif // BUILD_H
