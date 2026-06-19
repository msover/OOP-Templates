//
// Created by msover on 6/19/26.
//

#ifndef TEST_OBSERVER_H
#define TEST_OBSERVER_H



class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
};



#endif //TEST_OBSERVER_H
