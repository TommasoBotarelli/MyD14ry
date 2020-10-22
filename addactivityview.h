#ifndef ADDACTIVITYVIEW_H
#define ADDACTIVITYVIEW_H

#include <QDialog>

namespace Ui {
    class AddActivityView;
}

class AddActivityView : public QDialog {
Q_OBJECT

public:
    explicit AddActivityView(QWidget *parent = nullptr);

    ~AddActivityView();

private slots:

    void on_AddActivityButton_clicked();

    void on_AddSubActivityButton_clicked();

private:
    Ui::AddActivityView *ui;
};

#endif // ADDACTIVITYVIEW_H
