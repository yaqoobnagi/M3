#include <iostream>
#include "Date.h"

using namespace std;

int main() {
    // Test default constructor
    Date date1;
    cout << "Test default constructor: " << date1.printFormat1() << endl;  // Expected: 1/1/1900

    // Test constructor with valid date
    Date date2(2, 28, 2009);
    cout << "Test constructor with valid date: " << date2.printFormat1() << endl;  // Expected: 2/28/2009

    // Test constructor with invalid month
    Date date3(45, 2, 2009);
    cout << "Test constructor with invalid month (45, 2, 2009): " << date3.printFormat1() << endl;  // Expected: 1/1/1900

    // Test constructor with invalid day
    Date date4(2, 29, 2009);
    cout << "Test constructor with invalid day (2/29/2009): " << date4.printFormat1() << endl;  // Expected: 1/1/1900

    // Test setDate with bad month
    date1.setDate(13, 25, 2020);
    cout << "Test setDate with bad month (13): " << date1.printFormat1() << endl;  // Expected: 1/1/1900

    // Test setDate with bad day
    date1.setDate(4, 31, 2009);
    cout << "Test setDate with bad day (4, 31, 2009): " << date1.printFormat1() << endl;  // Expected: 1/1/1900

    // Test leap year with bad date (2/29/2009)
    date1.setDate(2, 29, 2009);
    cout << "Test for leap year with bad date (2/29/2009): " << date1.printFormat1() << endl;  // Expected: 1/1/1900

    // Test leap year with good date (2/29/2008)
    Date date5(2, 29, 2008);
    cout << "Test for leap year with good date (2/29/2008): " << date5.printFormat1() << endl;  // Expected: 2/29/2008

    // Test the print formats
    cout << "Test print formats:" << endl;
    cout << date5.printFormat2() << endl;  // Expected: February 29, 2008
    cout << date5.printFormat3() << endl;  // Expected: 29 February 2008

    return 0;
}
