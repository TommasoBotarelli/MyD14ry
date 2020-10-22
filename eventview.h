#ifndef EVENTVIEW_H
#define EVENTVIEW_H

#include <QDialog>

namespace Ui {
    class EventView;
}

class EventView : public QDialog {
Q_OBJECT

public:
    explicit EventView(QWidget *parent = nullptr);

    ~EventView();

private slots:

    void on_DeleteButton_clicked();

private:
    Ui::EventView *ui;
};

#endif // EVENTVIEW_H
