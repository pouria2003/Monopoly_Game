#ifndef PAIDRENTCONTAINER_H
#define PAIDRENTCONTAINER_H

#include <QWidget>

class PaidRent;
class Player;

class PaidRentContainer : public QWidget
{
    Q_OBJECT
public:
    explicit PaidRentContainer(QWidget *parent = nullptr);
    void Mshow(Player *payer, Player *payee, int rent);

public:
    PaidRent *paid_rent;
};

#endif // PAIDRENTCONTAINER_H
