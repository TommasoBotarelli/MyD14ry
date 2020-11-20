//
// Created by tommaso on 23/10/20.
//

#ifndef MYD14RY_SUBJECT_H
#define MYD14RY_SUBJECT_H

#include "Observer.h"

class Subject {

public:
    virtual ~Subject() {};

    Subject() {};

    virtual void addObserver(Observer *o) = 0;

    virtual void removeObserver(Observer *o) = 0;

    virtual void notify() const = 0;
};


#endif //MYD14RY_SUBJECT_H
