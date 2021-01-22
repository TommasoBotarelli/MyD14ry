#ifndef ALERTWINDOW_H
#define ALERTWINDOW_H

#include <QDialog>

namespace Ui {
    class AlertWindow;
}

class AlertWindow : public QDialog {
Q_OBJECT

public:
    explicit AlertWindow(QWidget *parent = nullptr);

    ~AlertWindow();

    bool getCancel() {
        return cancel;
    };

private slots:

    void on_ButtonElimina_clicked();

    void on_ButtonSposta_clicked();

private:
    Ui::AlertWindow *ui;

    bool cancel;
};

#endif // ALERTWINDOW_H
