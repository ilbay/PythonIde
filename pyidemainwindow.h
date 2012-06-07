#ifndef PYIDEMAINWINDOW_H
#define PYIDEMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class PyIdeMainWindow;
}

class PyIdeMainWindow : public QMainWindow
{
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
