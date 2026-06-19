#ifndef TEST_REPO_H
#define TEST_REPO_H

#include <vector>
#include "../Domain/Item.h"

class Repo {
public:
    void add(const Item& item);
    const std::vector<Item>& getAll() const;

private:
    std::vector<Item> items;
};

#endif // TEST_REPO_H
