#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("电子花名册");
    QIcon icon("../favicon.ico");
    w.setWindowIcon(icon);
    w.show();

    return a.exec();
}
