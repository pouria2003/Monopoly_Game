#include "monopoly.h"
#include "ui_monopoly.h"

Monopoly::Monopoly(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Monopoly)
{
    ui->setupUi(this);
}

Monopoly::~Monopoly()
{
    delete ui;
}

