#ifndef BUILDCONTAINER_H
#define BUILDCONTAINER_H

#include <QWidget>
#include <QPushButton>

class Build;

class BuildContainer : private QWidget
{
    Q_OBJECT
public:
    BuildContainer(QWidget * = nullptr);
    void createBuild(QVector<int> * sites);

private:
    Build *build;
    QPushButton *finish_button;

public slots:
    void Mhide();
};

#endif // BUILDCONTAINER_H
