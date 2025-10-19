#include "NumberArray.h"
#include <random>

int main() {
    NumberArray array1;
    array1.printArray();

    NumberArray array2(15);
    array2.printArray();

    std::default_random_engine generator(time(0));
    std::uniform_real_distribution<double> distribution(0.0, 100.0);
    for (int i = 0; i < 15; ++i) {
        array2.setNumber(i, distribution(generator));
    }
    array2.printArray();

    array2.setNumber(20, 55.0);

    std::cout << "Access item at index 5: " << array2.getNumber(5) << std::endl;
    std::cout << "Access item at index 20: " << array2.getNumber(20) << std::endl;

    std::cout << "Min: " << array2.getMin() << ", Max: " << array2.getMax() << ", Average: " << array2.getAverage() << std::endl;

    return 0;
}
