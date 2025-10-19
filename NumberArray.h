#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

class NumberArray {
private:
    int size;
    double* array;
    static const int MAX_SIZE = 10;
    static const double DEFAULT_VALUE = 10000.0;

public:
    NumberArray(int size = MAX_SIZE);
    ~NumberArray();
    void setNumber(int index, double value);
    double getNumber(int index) const;
    double getMin() const;
    double getMax() const;
    double getAverage() const;
    void printArray() const;

private:
    void initializeArray();
};

#endif
