#include "playersname.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGuiApplication>
#include <QScreen>

extern QVector<QString> players_info;

PlayersName::PlayersName(int _number_of_players) : number_of_players(_number_of_players)
{
    names_lbl = new QLabel*[number_of_players];
    names_le = new QLineEdit*[number_of_players];
    colors_lbl = new QLabel*[number_of_players];
    //colors_cb = new QComboBox*[number_of_players];

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

//        QIcon *ic = new QIcon(":/Images/red_player.png");

        //colors_cb[i] = createComboBox();
        //connect(colors_cb[i], SIGNAL(currentIndexChanged(int)), this, SLOT(alter_combo_boxes(int)));

        units_layout[i] = new QHBoxLayout();
        units_layout[i]->addWidget(names_lbl[i]);
        units_layout[i]->addWidget(names_le[i]);

//        units_layout[i]->addWidget()

        //units_layout[i]->addWidget(colors_cb[i]);

        names_le[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        main_layout->addLayout(units_layout[i]);
    }

    main_layout->addWidget(done_btn);

    main_layout->setContentsMargins(WINDOW_WIDTH/7, WINDOW_HEIGHT/5, WINDOW_WIDTH/5, WINDOW_HEIGHT/7);

    this->setLayout(main_layout);

    connect(done_btn, SIGNAL(clicked()), this, SLOT(done_btn_clicked()));
    connect(done_btn, SIGNAL(clicked()), this, SIGNAL(finish_this_page()));
}

void PlayersName::done_btn_clicked()
{
    for(int i = 0; i < number_of_players; ++i) {
        players_info << names_le[i]->text()/* + QString::number(colors_cb[i]->currentIndex())*/;
    }
}


//void PlayersName::alter_combo_boxes(int ind)
//{
//    for(int i = 0; i < 8; ++i) {
//        qDebug() << QString::number(colors_cb[i]->currentIndex());
//        if(i == ind)
//            continue;
//        if(colors_cb[i]->currentIndex() == colors_cb[ind]->currentIndex()) {
//            qDebug() << "tekrarie";
//            //done_btn->setDisabled(true);
//            return;
//        }
//    }
    //done_btn->setEnabled(true);

//    static bool color_choosed[8];
//    for(int i = 0; i < 8; ++i)
//        color_choosed[i] = false;

//    for(int i = 0; i < 8; ++i) {
//        if(color_choosed[colors_cb[i]->currentIndex()] == true) {
//            qDebug() << "tekrari";
//            done_btn->setDisabled(true);
//            return;
//        }
//        else {
//            //color_choosed[colors_cb[i]->currentIndex()] = true;
//        }
//    }
//    done_btn->setDisabled(false);
//}

// helper function to create a comboBox
QComboBox * PlayersName::createComboBox()
{

    static int curr_ind = 0;
    QComboBox * combo_box = new QComboBox();
    combo_box->addItem(QIcon(":/Images/red_player.png"), "RED");
    combo_box->addItem(QIcon(":/Images/blue_player.png"), "BLUE");
    combo_box->addItem(QIcon(":/Images/green_player.png"), "GREEN");
    combo_box->addItem(QIcon(":/Images/gray_player.png"), "GRAY");
    combo_box->addItem(QIcon(":/Images/yellow_player.png"), "YELLOW");
    combo_box->addItem(QIcon(":/Images/orange_player.png"), "ORANGE");
    combo_box->addItem(QIcon(":/Images/purple_player.png"), "PURPLE");
    combo_box->addItem(QIcon(":/Images/pink_player.png"), "PINK");

    combo_box->setCurrentIndex(curr_ind);
    ++curr_ind;

    return combo_box;
}
