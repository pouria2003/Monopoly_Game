#ifndef DEED_H
#define DEED_H

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QPushButton>

class PropertySpace;
class Player;

class Deed : public QGraphicsView
{
    Q_OBJECT
public:
    Deed(PropertySpace *, QWidget * = nullptr);
    void setPlayer(Player *);

public slots:
    void Mclose();

private:
    QGraphicsScene *scene;
    QGraphicsPixmapItem *item;
    PropertySpace *property;
    QPushButton *buy_btn;
    QPushButton *auction_btn;
    Player *player;
};

#endif // DEED_H
