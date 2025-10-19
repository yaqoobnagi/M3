#include "Date.h"
#include <iostream>
#include <sstream>

// Constructor (with default parameters)
Date::Date(int m, int d, int y) {
    setDate(m, d, y);
}

// Mutator function
void Date::setDate(int m, int d, int y) {
    if (m < 1 || m > 12) {
        cout << "Month invalid" << endl;
        month = 1;
        day = 1;
        year = 1900;
    } else if (d < 1 || d > lastDay(m, y)) {
        cout << "Day invalid" << endl;
        month = 1;
        day = 1;
        year = 1900;
    } else {
        month = m;
        day = d;
        year = y;
    }
}

// Leap year check (based on current year)
bool Date::isLeapYear() const {
    return isLeapYear(year);
}

// Leap year check (based on specified year)
bool Date::isLeapYear(int year) const {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Last day of month (based on current month and year)
int Date::lastDay() const {
    return lastDay(month, year);
}

// Last day of month (based on specified month and year)
int Date::lastDay(int month, int year) const {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0; // Invalid month
    }
}

// Print date as MM/DD/YYYY
string Date::printFormat1() const {
    stringstream ss;
    ss << month << "/" << day << "/" << year;
    return ss.str();
}

// Print date as Month Day, Year
string Date::printFormat2() const {
    static const string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    stringstream ss;
    ss << months[month - 1] << " " << day << ", " << year;
    return ss.str();
}

// Print date as Day Month Year
string Date::printFormat3() const {
    static const string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    stringstream ss;
    ss << day << " " << months[month - 1] << " " << year;
    return ss.str();
}
