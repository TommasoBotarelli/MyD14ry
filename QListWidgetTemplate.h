//
// Created by tommaso on 21/11/20.
//

#ifndef MYD14RY_QLISTWIDGETTEMPLATE_H
#define MYD14RY_QLISTWIDGETTEMPLATE_H

#include <QListWidgetItem>

template<typename T>
class QListWidgetTemplate : public QListWidgetItem {

public:
    void set(std::shared_ptr<T> d) {
        data = d;
    }

    std::shared_ptr<T> get() {
        return data;
    }

private:
    std::shared_ptr<T> data;
};


#endif //MYD14RY_QLISTWIDGETTEMPLATE_H
