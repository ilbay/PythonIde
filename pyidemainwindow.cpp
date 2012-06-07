#include "pyidemainwindow.h"
#include "ui_pyidemainwindow.h"
#include "aboutdialog.h"
#include "feedbackdialog.h"

PyIdeMainWindow::PyIdeMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::PyIdeMainWindow) {
    ui->setupUi(this);
}

PyIdeMainWindow::~PyIdeMainWindow() {
    delete ui;
}

void PyIdeMainWindow::on_actionAbout_triggered() {
    AboutDialog a;
    a.exec();
}

void PyIdeMainWindow::on_actionSendFeedback_triggered() {
    FeedbackDialog f;
    f.exec();
}

void PyIdeMainWindow::on_actionQuit_triggered() {
    this->close();
}
