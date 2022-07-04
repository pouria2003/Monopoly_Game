#ifndef DEEDCONTAINER_H
#define DEEDCONTAINER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "deed.h"
#include "propertyspace.h"

class DeedContainer : private QWidget
{
    Q_OBJECT
public:
    explicit DeedContainer(QWidget *parent = nullptr);
    void Mshow(PropertySpace *,Player *);
    void Mclose();
    ~DeedContainer();

public:
    Deed *deed;

private:
    QLabel *player_name_lbl;

};

#endif // DEEDCONTAINER_H
