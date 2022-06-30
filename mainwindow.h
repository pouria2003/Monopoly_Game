#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class GetPlayersNumber;
class PlayersName;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    GetPlayersNumber *first_page;
    PlayersName *players_name;

private slots:
    void getPlayersName();
    void startGame();

};

#endif // MAINWINDOW_H
