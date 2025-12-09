#include <iostream>
#include "NumberArray.h"

using namespace std;

int main() {

    cout << "----- Test constructors -----\n";

    NumberArray<int> intArr1;
    cout << "From default constructor: Integer array of size 10\n";
    intArr1.printArray();

    NumberArray<double> dblArr1;
    cout << "From default constructor: Double array of size 10\n";
    dblArr1.printArray();

    NumberArray<int> intArr2(15);
    cout << "From constructor with parameters: Integer array of size 15\n";
    intArr2.printArray();

    NumberArray<double> dblArr2(15);
    cout << "From constructor with parameters: Double array of size 15\n";
    dblArr2.printArray();


    cout << "----- Test mutator -----\n";
    for (int i = 0; i < 15; i++) {
        intArr2.setNumber(i, rand() % 100);
        dblArr2.setNumber(i, (rand() % 10000) / 100.0);
    }

    cout << "Integer array filled with numbers:\n";
    intArr2.printArray();

    cout << "Double array filled with numbers:\n";
    dblArr2.printArray();

    cout << "Trying to set a number with an out of bounds index (20):\n";
    try {
        intArr2.setNumber(20, 5);
    } catch (out_of_range& e) {
        cout << "Integer array ...\nThe index is out of the bounds of the array, number not stored\n";
    }

    try {
        dblArr2.setNumber(20, 5.5);
    } catch (out_of_range& e) {
        cout << "Double array ...\nThe index is out of the bounds of the array, number not stored\n";
    }

    cout << "----- Test accessors -----\n";
    try {
        cout << "Access integer item at index 5: " << intArr2.getNumber(5) << endl;
        cout << "Access double item at index 5: " << dblArr2.getNumber(5) << endl;
    } catch (...) {}

    cout << "Trying to access a number with an out of bounds index (20):\n";
    try {
        intArr2.getNumber(20);
    } catch (...) {
        cout << "Integer array ...\nThe index is out of the bounds of the array, number not stored\n";
    }

    try {
        dblArr2.getNumber(20);
    } catch (...) {
        cout << "Double array ...\nThe index is out of the bounds of the array, number not stored\n";
    }

    cout << "The minimum value in the integer array is: " << intArr2.getMin() << endl;
    cout << "The maximum value in the integer array is: " << intArr2.getMax() << endl;
    cout << "The average of the values in the integer array is: " << intArr2.getAverage() << endl;

    cout << "The minimum value in the double array is: " << dblArr2.getMin() << endl;
    cout << "The maximum value in the double array is: " << dblArr2.getMax() << endl;
    cout << "The average of the values in the double array is: " << dblArr2.getAverage() << endl;

    cout << "----- Print arrays -----\n";
    cout << "Integer array:\n";
    intArr2.printArray();

    cout << "Double array:\n";
    dblArr2.printArray();

    cout << "----- Test destructor -----\n";
    cout << "Exiting program, destructor will be called to free memory.\n";

    return 0;
}
