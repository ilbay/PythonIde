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

#include "feedbackdialog.h"
#include "ui_feedbackdialog.h"
#include "mail/SmtpMime"
#include <QtGui/QApplication>
#include <QMessageBox>


FeedbackDialog::FeedbackDialog(QWidget *parent) : QDialog(parent), ui(new Ui::FeedbackDialog) {
    ui->setupUi(this);
}

FeedbackDialog::~FeedbackDialog() {
    delete ui;
}

void FeedbackDialog::on_closeButton_clicked() {
    this->reject();
}

void FeedbackDialog::on_sendButton_clicked() {
    QString subject=ui->titleComboBox->currentText();
    QString textBody=ui->feedbackTextEdit->toPlainText();

    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    smtp.setUser("learnprogrammingbaris@gmail.com");
    smtp.setPassword("baris12345");

    MimeMessage message;
    message.setSender(new EmailAddress("learnprogrammingbaris@gmail.com", "Your Name"));
    message.addRecipient(new EmailAddress("dbarisakkurt@gmail.com", "Recipient's Name"));
    message.setSubject(subject);    //"SmtpClient for Qt - Demo"

    MimeText text;
    text.setText(textBody);
    message.addPart(&text);

    // Sending mail
    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();

    ui->sendStatusLabel->setText("Your message was delivered successfully.");

       //QMessageBox msgBox;
       //msgBox.setText("Your message was delivered successfully.");
       //msgBox.exec();
}
