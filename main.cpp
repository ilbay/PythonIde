/**********************************************************************************
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *********************************************************************************/

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
