//
// Created by marco on 23/10/20.
//

#ifndef MYD14RY_SUBACTIVITY_H
#define MYD14RY_SUBACTIVITY_H
#include <Qstring>


class SubActivity {

public:
    void setTask(const Qstring &task);
    const QString &getTask() const;
    bool isCompleted() const;
    void setCompleted(bool completed);

private:
    Qstring task;
    bool completed;

};


#endif //MYD14RY_SUBACTIVITY_H
