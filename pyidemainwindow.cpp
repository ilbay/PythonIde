#include "pyidemainwindow.h"
#include "ui_pyidemainwindow.h"
#include "aboutdialog.h"

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
