#include "mainwindow.h"

#include <QApplication>
#include <QWidget>
#include <QtCharts/QChart>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.grabGesture(Qt::PanGesture);
    w.grabGesture(Qt::PinchGesture);
    w.show();
    return a.exec();
}
