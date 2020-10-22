#ifndef ADDEVENTDIALOG_H
#define ADDEVENTDIALOG_H

#include <QDialog>

namespace Ui {
    class AddEventDialog;
}

class AddEventDialog : public QDialog {
Q_OBJECT

public:
    explicit AddEventDialog(QWidget *parent = nullptr);

    ~AddEventDialog();

private slots:

    void on_AddButton_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::AddEventDialog *ui;
};

#endif // ADDEVENTDIALOG_H
