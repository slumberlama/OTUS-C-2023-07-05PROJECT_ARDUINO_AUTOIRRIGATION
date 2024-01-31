#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setFixedSize(572, 478);
    w.setWindowTitle("Буль Буль (✿◠‿◠)");
    w.show();

    return a.exec();
}
