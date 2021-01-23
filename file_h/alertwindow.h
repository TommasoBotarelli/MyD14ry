#ifndef ALERTWINDOW_H
#define ALERTWINDOW_H

#include <QDialog>
#include "../file_h/ActivityListController.h"

namespace Ui {
    class AlertWindow;
}

class AlertWindow : public QDialog {
Q_OBJECT

public:
    explicit AlertWindow(ActivityListController *c, QString cat, QWidget *parent = nullptr);

    ~AlertWindow();

private slots:

    void on_ButtonElimina_clicked();

    void on_ButtonSposta_clicked();

private:
    Ui::AlertWindow *ui;

    ActivityListController *controller;

    QString category;
};

#endif // ALERTWINDOW_H
