#include <QtGui/QApplication>
#include <QThread>
#include <QSplashScreen>
#include "pyidemainwindow.h"

class CxTestSleepThread : public QThread {
public:
    /**
     *  this method is used to call sleep, as msleep is a protected function of
     *  QThread
     *
     *  @param nMSecs milliseconds to sleep
     */
    static void mySleep(int nMSecs) {
        msleep(nMSecs);
    }
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QPixmap pixmap(":/files/images/splashScreen.png");
    QSplashScreen *splash = new QSplashScreen(pixmap);
    splash->show();
    a.processEvents();
    splash->showMessage(QObject::tr("Loading modules..."));
    CxTestSleepThread::mySleep(500);
    a.processEvents();
    splash->showMessage(QObject::tr("Opening..."));
    CxTestSleepThread::mySleep(500);

    PyIdeMainWindow w;
    w.showMaximized();
    w.show();

    splash->finish(&w);
    delete splash;

    return a.exec();
}
