#ifndef TEST_ITEM_H
#define TEST_ITEM_H

#include <string>

class Item {
    std::string name;
    int value;
public:
    Item(std::string name, int value);
    const std::string& getName() const;
    int getValue() const;
};

#endif //TEST_ITEM_H
