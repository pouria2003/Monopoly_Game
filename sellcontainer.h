#ifndef SELLCONTAINER_H
#define SELLCONTAINER_H

#include <QWidget>
#include <QPushButton>

class Sell;

class SellContainer : public QWidget
{
    Q_OBJECT
public:
    explicit SellContainer(QWidget *parent = nullptr);
    void createSell(QVector<int> *sites);

private:
    Sell *sell;
    QPushButton *finish_button;


public slots:
    void Mhide();
};

#endif // SELLCONTAINER_H
