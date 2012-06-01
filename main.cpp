#include <QtGui/QApplication>
#include "pyidemainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    PyIdeMainWindow w;
    w.show();
    
    return a.exec();
}
