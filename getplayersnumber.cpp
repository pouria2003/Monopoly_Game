#include "getplayersnumber.h"
#include <QFont>
#include <QVBoxLayout>
#include <QGuiApplication>
#include <QScreen>
#include "playersname.h"

GetPlayersNumber::GetPlayersNumber(QWidget *parent) : QWidget(parent)
{

    players_num = 2;

    player_num_lbl = new QLabel();
    player_num_lbl->setText("Choose number of players");

    player_num_sld = new QSlider;
    player_num_sld->setOrientation(Qt::Horizontal);

    player_num_sld->setMinimum(2);
    player_num_sld->setMaximum(8);

    show_player_num = new QLabel();


    done_btn = new QPushButton("Done");

    int WINDOW_WIDTH = QGuiApplication::screens().at(0)->availableGeometry().width();
    int WINDOW_HEIGHT = QGuiApplication::screens().at(0)->availableGeometry().height();

    //this->setAutoFillBackground(true);
    QPalette palette = this->palette();

    palette.setBrush(QPalette::Window, QBrush
                     (QPixmap(":/Images/haj_agha.jpg").scaled(QSize(WINDOW_WIDTH, WINDOW_HEIGHT), Qt::IgnoreAspectRatio)));
    this->setPalette(palette);

    player_num_lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    player_num_sld->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    show_player_num->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    done_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    QVBoxLayout *v_layout = new QVBoxLayout;

    v_layout->setContentsMargins(WINDOW_WIDTH/8, WINDOW_HEIGHT/12, WINDOW_WIDTH/8, WINDOW_HEIGHT/12);

    v_layout->addWidget(player_num_lbl);
    v_layout->addWidget(player_num_sld);
    v_layout->addWidget(show_player_num);
    v_layout->addWidget(done_btn);

    this->setLayout(v_layout);

    connect(player_num_sld, SIGNAL(valueChanged(int)), show_player_num, SLOT(setNum(int)));
    connect(player_num_sld, SIGNAL(valueChanged(int)), this, SLOT(num_changed(int)));
    connect(done_btn,  &QPushButton::clicked, this, &GetPlayersNumber::players_num_gotted);

}

void GetPlayersNumber::num_changed(int new_val)
{
    players_num = new_val;
}
