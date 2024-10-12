//============================================================================
// Name        : date.h
// Author      : Evan Schubert
//============================================================================
#ifndef DATE_H
#define DATE_H
#include <string>

class Date {
public:
    Date(int month, int day, int year);
    Date();

    int month() const;
    int day() const;
    int year() const;

    std::string to_string() const;
    bool earlier(Date d1, Date d2);

private:
    int _month;
    int _day;
    int _year;
};

// Document the Date class by describing *what* it does, not how it does
// it; that is, what are its responsibilities?
// It initializes a date (month/day/year) into a list. It has getter functions
// for all of the class variables. A method that prints out a human-readable
// string for a date. Additionally it has a method to compare two dates
// to see which one occurred earlier.


#endif //DATE_H