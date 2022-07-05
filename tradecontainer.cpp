#include "tradecontainer.h"
#include <QGuiApplication>
#include <QScreen>
#include "street.h"
#include "monopoly.h"

TradeContainer::TradeContainer(QWidget *parent)
    : QWidget{parent}
{
    trade = new Trade(this);
    trade->hide();
    QWidget::setWindowFlags(Qt::Window);

    players_names = new QComboBox(this);
    choose_lbl = new QLabel(this);
    trade_btn = new QPushButton(this);

    layout = new QGridLayout(this);

    my_name = new QLabel(this);
    other_name = new QLabel(this);

    my_name->hide();
    other_name->hide();

    this->setGeometry(200, 200, 300, 200);
    this->hide();

}

void TradeContainer::createTrade(int current_player_index, const QVector<Player *> *_players, const QHash<int, PropertySpace *> *_property_spaces)
{
    my_index = current_player_index;

    players = _players;
    property_spaces = _property_spaces;

    trade_btn->setText("Trade");
    choose_lbl->setText("choose witch player to trade");


    for(int i = 0; i < players->size(); ++i) {
        if(i != current_player_index) {
            players_names->addItem(players->operator[](i)->getName());
        }
    }


    layout->addWidget(choose_lbl, 0, 0);
    layout->addWidget(players_names, 0, 1);
    layout->addWidget(trade_btn, 1, 0, 1, 1);
    this->setLayout(layout);

    int WINDOW_WIDTH = QGuiApplication::screens().at(0)->availableGeometry().width();
    int WINDOW_HEIGHT = QGuiApplication::screens().at(0)->availableGeometry().height();

    layout->setContentsMargins(WINDOW_WIDTH/10, WINDOW_HEIGHT/6, WINDOW_WIDTH/10, WINDOW_HEIGHT/6);

    connect(trade_btn, SIGNAL(clicked()), this, SLOT(tradeClicked()));

    this->show();
}

QVector<int> *TradeContainer::playerProperties(int index)
{
    QVector<int> *result = new QVector<int>;
    for(int i = 0; i < 40; ++i) {
        if(property_spaces->contains(i) && property_spaces->value(i)->owner == players->value(index)) {
            if(typeid(*(property_spaces->value(i))) != typeid(Street) || property_spaces->value(i)->level == 0)
                result->push_back(i);
        }
    }
    return result;
}

void TradeContainer::doTrade(QVector<int> *deedsYouGive, QVector<int> *deedsYouGet, int moneyYoyGive, int moneyYouGet)
{
    for(int i = 0; i < deedsYouGive->size(); ++i ) {
        property_spaces->value(deedsYouGive->value(i))->owner = players->value(other_index);
        Monopoly::instance()->setPropertyOwner(players->value(other_index), deedsYouGive->value(i));
    }

    for(int i = 0; i < deedsYouGet->size(); ++i ) {
        property_spaces->value(deedsYouGet->value(i))->owner = players->value(my_index);
        Monopoly::instance()->setPropertyOwner(players->value(my_index), deedsYouGet->value(i));
    }

    players->value(my_index)->changeMoney(moneyYouGet);
    players->value(other_index)->changeMoney(moneyYoyGive);

    this->Mhide();
}

void TradeContainer::tradeClicked()
{
    other_index = players_names->currentIndex();
    if (other_index >= my_index)
        ++other_index;

    players_names->hide();
    choose_lbl->hide();
    trade_btn->hide();

    my_name->setText(players->value(my_index)->getName());
    other_name->setText(players->value(other_index)->getName());

    my_name->show();
    other_name->show();

    my_name->setGeometry(50, 50, 100, 30);
    other_name->setGeometry(450, 50, 100, 30);

    this->setGeometry(200, 200, 800, 600);

    trade->setTrade(playerProperties(my_index), playerProperties(other_index), 10000, 10000);
    trade->setGeometry(0, 0, 800, 600);
    trade->show();
}

void TradeContainer::Mhide()
{
    my_name->hide();
    other_name->hide();
    trade->Mhide();
    this->hide();
}

