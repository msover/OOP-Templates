#ifndef TEST_FILTER_H
#define TEST_FILTER_H

class Filter {
public:
    explicit Filter(double minValue);
    double getMinValue() const;
private:
    double minValue;
};

#endif // TEST_FILTER_H
