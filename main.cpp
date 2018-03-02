#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "C:\Users\Ian\Documents\GitHub\wiPiTools\wiPiTools.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
