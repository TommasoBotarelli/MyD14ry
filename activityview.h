#ifndef ACTIVITYVIEW_H
#define ACTIVITYVIEW_H

#include <QDialog>

namespace Ui {
    class ActivityView;
}

class ActivityView : public QDialog {
Q_OBJECT

public:
    explicit ActivityView(QWidget *parent = nullptr);

    ~ActivityView();

private slots:

    void on_SubActivityListWidget_itemChanged(QListWidgetItem *item);

    void on_AddSubactivityButton_clicked();

    void on_pushButton_clicked();

    void on_DeleteButton_clicked();

private:
    Ui::ActivityView *ui;
};

#endif // ACTIVITYVIEW_H
