#ifndef ADDSUBACTIVITYDIALOG_H
#define ADDSUBACTIVITYDIALOG_H

#include <QDialog>

namespace Ui {
    class AddSubActivityDialog;
}

class AddSubActivityDialog : public QDialog {
Q_OBJECT

public:
    explicit AddSubActivityDialog(QWidget *parent = nullptr);

    ~AddSubActivityDialog();

private slots:

    void on_AddButton_clicked();

private:
    Ui::AddSubActivityDialog *ui;
};

#endif // ADDSUBACTIVITYDIALOG_H
