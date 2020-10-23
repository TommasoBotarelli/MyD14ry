//
// Created by marco on 23/10/20.
//

#ifndef MYD14RY_OBSERVER_H
#define MYD14RY_OBSERVER_H


class Observer {

public:
    virtual ~Observer() {};
    virtual void update()=0;
    virtual void attach()=0;
    virtual void detach()=0;
};


#endif //MYD14RY_OBSERVER_H
