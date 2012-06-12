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

#ifndef PYIDEMAINWINDOW_H
#define PYIDEMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class PyIdeMainWindow;
}

/**
  @author D. Baris Akkurt
  @first creation date: 1.6.2012
  @revision date: 12.6.2012
*/
class PyIdeMainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    explicit PyIdeMainWindow(QWidget *parent = 0);
    ~PyIdeMainWindow();
    
private slots:
    void on_actionAbout_triggered();

    void on_actionSendFeedback_triggered();

    void on_actionQuit_triggered();

private:
    Ui::PyIdeMainWindow *ui;
};

#endif // PYIDEMAINWINDOW_H
