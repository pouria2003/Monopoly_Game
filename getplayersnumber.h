#ifndef GETPLAYERSNUMBER_H
#define GETPLAYERSNUMBER_H

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QPushButton>

class GetPlayersNumber : public QWidget {
    Q_OBJECT

public:
    GetPlayersNumber(QWidget * = nullptr);

private:
    QLabel *player_num_lbl;
    QLabel *show_player_num;
    QSlider *player_num_sld;
    QPushButton *done_btn;

public:
    int players_num;

private slots:
//    void done_clicked();
    void num_changed(int);

signals:
    void players_num_gotted();
};

#endif // GETPLAYERSNUMBER_H
