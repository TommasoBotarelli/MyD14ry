//
// Created by tommaso on 21/11/20.
//

#ifndef MYD14RY_QLISTWIDGETTEMPLATE_H
#define MYD14RY_QLISTWIDGETTEMPLATE_H

#include <QListWidgetItem>

template<typename T>
class QListWidgetTemplate : public QListWidgetItem {
public:
    void set(const T &d) {
        data = d;
    }

    T *get() {
        T *p;
        p = &data;
        return p;
    }
private:
    T data;
};


#endif //MYD14RY_QLISTWIDGETTEMPLATE_H
