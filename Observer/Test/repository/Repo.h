#ifndef TEST_REPO_H
#define TEST_REPO_H

#include <vector>
#include "../domain/Item.h"
#include "../observer/Observable.h"

class Repo : public Observable {
    std::vector<Item> items;
public:
    void add(const Item& item);
    const std::vector<Item>& getAll() const;
};

#endif //TEST_REPO_H
