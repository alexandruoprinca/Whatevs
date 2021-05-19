#include "mainwindow.h"
//#include "LoginTypeWindow.h"
#include <QApplication>
#include "TrenchCoat.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType<TrenchCoat>();
    QMetaType::registerConverter(&TrenchCoat::toString);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
