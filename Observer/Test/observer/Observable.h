#ifndef TEST_OBSERVABLE_H
#define TEST_OBSERVABLE_H

#include <vector>
#include "Observer.h"

class Observable {
    std::vector<Observer*> observers;
public:
    virtual ~Observable() = default;

    void addObserver(Observer* o) {
        observers.push_back(o);
    }

    void notifyAll() {
        for (auto* o : observers) o->update();
    }
};

#endif //TEST_OBSERVABLE_H
