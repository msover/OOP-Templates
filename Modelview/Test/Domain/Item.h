#ifndef TEST_ITEM_H
#define TEST_ITEM_H

#include <string>

class Item {
public:
    Item(std::string name, double value);

    const std::string& getName() const;
    double getValue() const;

    void setName(std::string name);
    void setValue(double value);

private:
    std::string name;
    double value;
};

#endif // TEST_ITEM_H
