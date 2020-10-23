//
// Created by marco on 23/10/20.
//

#ifndef MYD14RY_SUBACTIVITY_H
#define MYD14RY_SUBACTIVITY_H

#include <QString>


class SubActivity {

public:

    void setTask(const QString &task);

    const QString &getTask() const;

    bool isCompleted() const;

    void setCompleted(bool completed);

private:

    QString task;

    bool completed;

};


#endif //MYD14RY_SUBACTIVITY_H
