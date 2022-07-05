#ifndef MORTGAGECONTAINER_H
#define MORTGAGECONTAINER_H

#include <QWidget>
#include "QGraphicsPixmapItem"
#include "QPushButton"
#include "mortgage.h"


class MortgageContainer : public QWidget
{
    Q_OBJECT
public:
    explicit MortgageContainer(QWidget *parent = nullptr);
    void createMortgage(QVector<int> * sites);

private:
    Mortgage *mortgage;
    QPushButton *finish_button;

public slots:
    void Mhide();

};

#endif // MORTGAGECONTAINER_H
