#include "Item.h"
#include <utility>

Item::Item(std::string name, double value)
    : name{std::move(name)}, value{value} {}

const std::string& Item::getName() const { return name; }
double Item::getValue() const { return value; }
void Item::setName(std::string name) { this->name = std::move(name); }
void Item::setValue(double value) { this->value = value; }
