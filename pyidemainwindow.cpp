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

#include <QDir>
#include <QDebug>
#include <QList>
#include <QFileInfoList>
#include <QMessageBox>
#include <QtCore>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QCloseEvent>
#include <QPushButton>
#include <QWidget>
#include "pyidemainwindow.h"
#include "ui_pyidemainwindow.h"
#include "aboutdialog.h"
#include "feedbackdialog.h"
#include "preferencesdialog.h"

PyIdeMainWindow::PyIdeMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::PyIdeMainWindow) {
    ui->setupUi(this);

    ui->actionCut->setEnabled(false);
    ui->actionCopy->setEnabled(false);
    ui->actionPaste->setEnabled(false);
    ui->actionDelete->setEnabled(false);

    denemeButton=new QPushButton("click me");

    welcomePage=new QTextEdit;
    welcomePage->setText("<h1>Welcome to Python ide.<h1>");
    welcomePage->setReadOnly(true);

    exampleListWidget=new QListWidget(this);
    // Adding Python examples to hello page.
    QDir exampleDir("../PyIde/codeSnippets");
    QFileInfoList exampleList;
    exampleList=exampleDir.entryInfoList(QDir::Files);

    for(int i=0; i<exampleList.size(); i++) {
        exampleListWidget->addItem(exampleList.at(i).fileName());
    }


    v1=new QVBoxLayout();
    v1->addWidget(denemeButton);
    v1->addWidget(welcomePage);
    v1->addWidget(exampleListWidget);
    this->centralWidget()->setLayout(v1);

    connect(denemeButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));

}

void PyIdeMainWindow::closeEvent(QCloseEvent *event) {
    bool willQuit=false;

    QMessageBox::StandardButton ret;
    ret = QMessageBox::warning(this, tr("Application"), tr("Are you sure to quit?"), QMessageBox::Ok | QMessageBox::Cancel);

    if(ret == QMessageBox::Ok)
        willQuit=true;
    else
        willQuit=false;

    if (willQuit==true) {
        event->accept();
     } else {
        event->ignore();
     }
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

void PyIdeMainWindow::on_actionPreferences_triggered() {
    PreferencesDialog p;
    p.exec();
}

void PyIdeMainWindow::buttonClicked() {
    qDebug() << "bar";
    delete welcomePage;
    delete denemeButton;
    delete exampleListWidget;

    QPushButton *qpb=new QPushButton("bar");
    v1->addWidget(qpb);

}
