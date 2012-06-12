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

#ifndef FEEDBACKDIALOG_H
#define FEEDBACKDIALOG_H

#include <QDialog>

namespace Ui {
class FeedbackDialog;
}


/**
  @author D. Baris Akkurt
  @first creation date: 1.6.2012
  @revision date: 12.6.2012
*/
class FeedbackDialog : public QDialog {
    Q_OBJECT
    
public:
    explicit FeedbackDialog(QWidget *parent = 0);
    ~FeedbackDialog();
    
private slots:
    void on_closeButton_clicked();
    void on_sendButton_clicked();

private:
    Ui::FeedbackDialog *ui;
};

#endif // FEEDBACKDIALOG_H
