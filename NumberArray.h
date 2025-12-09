#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>

template <class T>
class NumberArray {
private:
    int size;
    T* array;

public:
    // Constructors
    NumberArray(int size = 10);
    NumberArray(const NumberArray& obj);

    // Destructor
    ~NumberArray();

    // Mutator
    void setNumber(int index, T value);

    // Accessor
    T getNumber(int index) const;

    // Stats
    T getMin() const;
    T getMax() const;
    double getAverage() const;

    // Display
    void printArray() const;
};

//---------------------------------------------
// Constructor
//---------------------------------------------
template<class T>
NumberArray<T>::NumberArray(int size) : size(size) {
    array = new T[size];
    for (int i = 0; i < size; i++)
        array[i] = 0;
}

//---------------------------------------------
// Copy Constructor
//---------------------------------------------
template<class T>
NumberArray<T>::NumberArray(const NumberArray& obj) {
    size = obj.size;
    array = new T[size];
    for (int i = 0; i < size; i++)
        array[i] = obj.array[i];
}

//---------------------------------------------
// Destructor
//---------------------------------------------
template<class T>
NumberArray<T>::~NumberArray() {
    delete[] array;
    std::cout << "The destructor is running\n";
}

//---------------------------------------------
// Mutator — now throws out_of_range
//---------------------------------------------
template<class T>
void NumberArray<T>::setNumber(int index, T value) {
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of bounds");

    array[index] = value;
}

//---------------------------------------------
// Accessor — now throws out_of_range
//---------------------------------------------
template<class T>
T NumberArray<T>::getNumber(int index) const {
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of bounds");

    return array[index];
}

//---------------------------------------------
// Minimum
//---------------------------------------------
template<class T>
T NumberArray<T>::getMin() const {
    T minVal = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] < minVal)
            minVal = array[i];
    return minVal;
}

//---------------------------------------------
// Maximum
//---------------------------------------------
template<class T>
T NumberArray<T>::getMax() const {
    T maxVal = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > maxVal)
            maxVal = array[i];
    return maxVal;
}

//---------------------------------------------
// Average
//---------------------------------------------
template<class T>
double NumberArray<T>::getAverage() const {
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum += array[i];
    return sum / size;
}

//---------------------------------------------
// Print array
//---------------------------------------------
template<class T>
void NumberArray<T>::printArray() const {
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

#endif
