#include "chance_chest.h"
#include <QGraphicsPixmapItem>

Chance_Chest::Chance_Chest(QWidget * parent) : QGraphicsView(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    card = new QGraphicsPixmapItem;
    scene = new QGraphicsScene();
    scene->addItem(card);
    this->setScene(scene);
}

void Chance_Chest::setChanceChest(NonPropertySpaceKind kind, int number)
{
    QString image_path;
    if(kind == Chance) {
        image_path = ":/Images/chance_";
    }
    else if (kind == Chest) {
        image_path = ":/Images/chest_";
    }
    image_path += QString::number(number) + ".png";

    card->setPixmap(QPixmap(image_path));

}
