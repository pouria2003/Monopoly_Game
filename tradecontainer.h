#ifndef TRADECONTAINER_H
#define TRADECONTAINER_H

#include <QWidget>
#include "trade.h"
#include "player.h"
#include "propertyspace.h"
#include <QComboBox>
#include <QGridLayout>
#include <QLabel>

class TradeContainer : public QWidget
{
    Q_OBJECT
public:
    explicit TradeContainer(QWidget *parent = nullptr);
    void createTrade(int current_player_index, const QVector<Player *> *players, const QHash<int, PropertySpace *> *property_space);
    QVector<int> *playerProperties(int index);
    void doTrade(QVector<int> *deedsYouGive, QVector<int> *deedsYouGet, int moneyYoyGive, int moneyYouGet);


private:
    Trade *trade;
    const QVector<Player *> *players;
    const QHash<int, PropertySpace *> *property_spaces;
    QComboBox *players_names = new QComboBox();
    QGridLayout *layout;
    QLabel *choose_lbl;
    QPushButton *trade_btn;

    QLabel *my_name;
    QLabel *other_name;


    int my_index;
    int other_index;



private slots:
    void tradeClicked();
    void Mhide();
};

#endif // TRADECONTAINER_H
