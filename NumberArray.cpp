#include "NumberArray.h"

NumberArray::NumberArray(int size) : size(size) {
    array = new double[size];
    initializeArray();
    std::cout << "Array of size " << size << std::endl;
}

NumberArray::~NumberArray() {
    delete[] array;
    std::cout << "The destructor is running" << std::endl;
}

void NumberArray::initializeArray() {
    for (int i = 0; i < size; ++i) {
        array[i] = 0.0;
    }
}

void NumberArray::setNumber(int index, double value) {
    if (index >= 0 && index < size) {
        array[index] = value;
    } else {
        std::cout << "The index is out of bounds of the array, number not stored" << std::endl;
    }
}

double NumberArray::getNumber(int index) const {
    return (index >= 0 && index < size) ? array[index] : DEFAULT_VALUE;
}

double NumberArray::getMin() const {
    double minVal = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] < minVal) minVal = array[i];
    }
    return minVal;
}

double NumberArray::getMax() const {
    double maxVal = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] > maxVal) maxVal = array[i];
    }
    return maxVal;
}

double NumberArray::getAverage() const {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) sum += array[i];
    return sum / size;
}

void NumberArray::printArray() const {
    for (int i = 0; i < size; ++i) {
        std::cout << std::fixed << std::setprecision(1) << array[i] << " ";
    }
    std::cout << std::endl;
}
