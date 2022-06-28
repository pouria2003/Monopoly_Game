#include "mainwindow.h"
#include "playersname.h"
#include "monopoly.h"
#include "firstpage.h"
#include <QFile>

QVector<QString> players_info;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
//    QFile styleF;

//    styleF.setFileName(":/styles/styles.css");
//    styleF.open(QFile::ReadOnly);
//    QString qssStr = styleF.readAll();

//    this->setStyleSheet(qssStr);

    first_page = new FirstPage;

    this->setCentralWidget(first_page);

//    connect(first_page, SIGNAL(players_num_gotted(int)), this, SIGNAL(getPlayersName(int)));
    connect(first_page, &FirstPage::players_num_gotted, this, &MainWindow::getPlayersName);
}

void MainWindow::getPlayersName()
{
    players_name = new PlayersName(first_page->players_num);
    setCentralWidget(players_name);
    connect(players_name, &PlayersName::finish_this_page, this, &MainWindow::startGame);
}

void MainWindow::startGame()
{
    this->resize(800, 800);
    Monopoly *monopoly = Monopoly::createInstance(players_info);
    setCentralWidget(monopoly);
}
