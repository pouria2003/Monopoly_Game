#ifndef FIRSTPAGE_H
#define FIRSTPAGE_H

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QPushButton>

class FirstPage : public QWidget {
    Q_OBJECT

public:
    FirstPage(QWidget * = nullptr);

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

#endif // FIRSTPAGE_H
