//
// Created by tommaso on 21/11/20.
//

#ifndef MYD14RY_QLISTWIDGETTEMPLATE_H
#define MYD14RY_QLISTWIDGETTEMPLATE_H

#include <QListWidgetItem>

template<typename T>
class QListWidgetTemplate : public QListWidgetItem {
public:
    void set(T *d) {
        data = d;
    }

    T *get() {
        return data;
    }

private:
    T *data;
};


#endif //MYD14RY_QLISTWIDGETTEMPLATE_H
