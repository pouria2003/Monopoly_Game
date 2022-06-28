#ifndef PLAYERSNAME_H
#define PLAYERSNAME_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>

class PlayersName : public QWidget
{
    Q_OBJECT

public:
    PlayersName(int number_of_players);
    virtual ~PlayersName() {};

private:
    QLabel **names_lbl;
    QLineEdit **names_le;
    QLabel **colors_lbl;
    //QComboBox **colors_cb;
    QPushButton *done_btn;

    int number_of_players;

private:
    QComboBox* createComboBox();

public slots:
    void done_btn_clicked();
//    void alter_combo_boxes(int);

signals:
    void finish_this_page();
};

#endif // PLAYERSNAME_H
