#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    // Constructors
    Date(int m = 1, int d = 1, int y = 1900);  // Default and parameterized constructor

    // Mutator function
    void setDate(int m, int d, int y);

    // Accessor functions
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    // Leap year functions
    bool isLeapYear() const;
    bool isLeapYear(int year) const;

    // Last day of month functions
    int lastDay() const;
    int lastDay(int month, int year) const;

    // Print functions
    string printFormat1() const; // MM/DD/YYYY
    string printFormat2() const; // Month Day, Year
    string printFormat3() const; // Day Month Year
};

#endif
