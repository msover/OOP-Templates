#include "Item.h"

Item::Item(std::string name, int value)
    : name(std::move(name)), value(value) {}

const std::string& Item::getName() const { return name; }
int Item::getValue() const { return value; }
