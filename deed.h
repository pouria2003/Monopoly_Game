#ifndef DEED_H
#define DEED_H

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QPushButton>

class PropertySpace;
class Player;
class DeedContainer;


class Deed : public QGraphicsView
{
    Q_OBJECT
public:
    Deed(DeedContainer *, QWidget * = nullptr);
//    ~Deed();
    void setPlayer(Player *);
    void setDeed(PropertySpace *, Player *);



private:
    DeedContainer *container;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *item;
    PropertySpace *property;
    QPushButton *buy_btn;
    QPushButton *auction_btn;
    Player *player;

    QGraphicsTextItem *name_txt;
    QGraphicsTextItem *rent_txt;
    QGraphicsTextItem *one_lvl_up_txt;
    QGraphicsTextItem *two_lvl_up_txt;
    QGraphicsTextItem *three_lvl_up_txt;
    QGraphicsTextItem *four_lvl_up_txt;
    QGraphicsTextItem *five_lvl_up_txt;
    QGraphicsTextItem *mortgage_txt;
    QGraphicsTextItem *explanation1_txt;
    QGraphicsTextItem *explanation2_txt;
    QGraphicsTextItem *price_txt;



public slots:
    void Mclose();
    void buy();
    void auction();

};

#endif // DEED_H
