#ifndef ADDCATEGORY_H
#define ADDCATEGORY_H

#include <QDialog>
#include "file_h/ActivityListController.h"
#include "file_h/ActivityList.h"

namespace Ui {
    class AddCategory;
}

class AddCategory : public QDialog {
Q_OBJECT

public:
    explicit AddCategory(ActivityListController *c, QWidget *parent = nullptr);

    ~AddCategory() override;

private slots:

    void on_addCategoryButton_clicked();

private:
    Ui::AddCategory *ui;

    ActivityListController *controller;
};

#endif // ADDCATEGORY_H
