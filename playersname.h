#ifndef PLAYERSNAME_H
#define PLAYERSNAME_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>

class PlayersName : public QWidget
{
public:
    PlayersName(int number_of_players);

private:
    QLabel **names_lbl;
    QLineEdit **names_le;
    QComboBox **colors_cb;
    QPushButton *done_btn;

    int number_of_players;

private:
    QComboBox* createComboBox();

private slots:
    void done_btn_clicked();
    void alter_combo_boxes(int);
};

#endif // PLAYERSNAME_H
