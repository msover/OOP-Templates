#include "Filter.h"

Filter::Filter(double minValue) : minValue{minValue} {}
double Filter::getMinValue() const { return minValue; }
