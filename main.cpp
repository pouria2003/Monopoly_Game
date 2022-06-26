#include "monopoly.h"
#include "firstpage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Monopoly w;
//    w.show();
    FirstPage f;
    f.show();

    return a.exec();
}
