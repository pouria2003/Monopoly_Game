#ifndef INJAIL_H
#define INJAIL_H

#include <QDialog>
#include <QPushButton>
#include <QHBoxLayout>

class Player;

class InJail : public QWidget
{
public:
    explicit InJail(QWidget *parent = nullptr);
    void Mshow(Player *);

public:
    QPushButton *use_card;
    QPushButton *role_dice;
    QPushButton *pay;
    QHBoxLayout *layout;


};

#endif // INJAIL_H
