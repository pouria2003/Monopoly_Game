#ifndef MONOPOLY_H
#define MONOPOLY_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Monopoly; }
QT_END_NAMESPACE

class Monopoly : public QMainWindow
{
    Q_OBJECT

public:
    Monopoly(QWidget *parent = nullptr);
    ~Monopoly();

private:
    Ui::Monopoly *ui;
};
#endif // MONOPOLY_H
