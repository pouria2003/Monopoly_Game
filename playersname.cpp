#include "playersname.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGuiApplication>
#include <QScreen>

#include <QDebug>



PlayersName::PlayersName(int _number_of_players) : number_of_players(_number_of_players)
{
    names_lbl = new QLabel*[number_of_players];
    names_le = new QLineEdit*[number_of_players];
    colors_cb = new QComboBox*[number_of_players];

    done_btn = new QPushButton("Done");

    QVBoxLayout *main_layout = new QVBoxLayout;
    QHBoxLayout **units_layout = new QHBoxLayout*[number_of_players];

    int WINDOW_WIDTH = QGuiApplication::screens().at(0)->availableGeometry().width();
    int WINDOW_HEIGHT = QGuiApplication::screens().at(0)->availableGeometry().height();

    QPalette palette = this->palette();

    palette.setBrush(QPalette::Window, QBrush
                     (QPixmap(":/Images/name_page_bg.jpg").scaled(QSize(WINDOW_WIDTH, WINDOW_HEIGHT), Qt::IgnoreAspectRatio)));
    this->setPalette(palette);

   done_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    for(int i = 0; i < number_of_players; ++i) {
        names_lbl[i] = new QLabel("Player " + QString::number(i + 1) + " name : ");
        names_le[i] = new QLineEdit("player " + QString::number(i + 1));
        colors_cb[i] = createComboBox();
        qDebug() << "here3";
        connect(colors_cb[i], SIGNAL(currentIndexChanged(int)), this, SLOT(alter_combo_boxes(int)));
        qDebug() << "here2";
        units_layout[i] = new QHBoxLayout();
        units_layout[i]->addWidget(names_lbl[i]);
        units_layout[i]->addWidget(names_le[i]);
        units_layout[i]->addWidget(colors_cb[i]);
        names_le[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        main_layout->addLayout(units_layout[i]);
    }

    main_layout->addWidget(done_btn);

    main_layout->setContentsMargins(WINDOW_WIDTH/7, WINDOW_HEIGHT/5, WINDOW_WIDTH/5, WINDOW_HEIGHT/7);

    connect(done_btn, SIGNAL(clicked()), this, SLOT(done_btn_clicked()));

    this->setLayout(main_layout);

}

void PlayersName::done_btn_clicked()
{
    // next widget
}

// helper function to create a comboBox
QComboBox * PlayersName::createComboBox()
{

    static int curr_ind = 0;
    QComboBox * combo_box = new QComboBox();
    combo_box->addItem("1");
    combo_box->addItem("2");
    combo_box->addItem("3");
    combo_box->addItem("4");
    combo_box->addItem("5");
    combo_box->addItem("6");
    combo_box->addItem("7");
    combo_box->addItem("8");

    combo_box->setCurrentIndex(curr_ind);
    ++curr_ind;

    return combo_box;
}

void PlayersName::alter_combo_boxes(int ind)
{
    qDebug() << "here1";

    for(int i = 0; i < number_of_players; ++i) {
        colors_cb[i]->removeItem(ind);
    }
}
