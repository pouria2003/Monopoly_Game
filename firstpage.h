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

private slots:
    void done_btn_clicked();
};

#endif // FIRSTPAGE_H
