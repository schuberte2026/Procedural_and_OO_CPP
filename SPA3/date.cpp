// SPA 3, Fall 2024, Schubert
//============================================================================
// Name        : date.cpp
// Author      : Evan Schubert
//============================================================================

//
// Make no changes to this file other than the TODOs below
//

#include "date.h"

#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

Date::Date(int month, int day, int year)
    : _month{month}, _day{day}, _year{year}
{ }

Date::Date() : _month{0}, _day{0}, _year{0} { }

int Date::month() const {
    return _month;
}

int Date::day() const {
    return _day;
}

int Date::year() const {
    return _year;
}

string Date::to_string() const
{
    // ostringstreams provide an cout-like interface but store the results
    //   in a std:string instead of files; this convert data into a string
    ostringstream formatted;
    formatted << std::setw(2) << std::setfill('0') << _month << "/";
    formatted << std::setw(2) << std::setfill('0') << _day << "/";
    formatted << std::setw(4) << std::setfill('0') << _year;

    return formatted.str();
}

bool Date::earlier(Date d1, Date d2)
{
    if (d1.year() != d2.year()) {
        return d1.year() < d2.year();
    }
    //continues if years were the same
    if (d1.month() != d2.month()) {
        return d1.month() < d2.month();
    }
    //continues if months were the same
    if (d1.day () != d2.day ()) {
        return d1.day() < d2.day();
    }
    return false; //both dates are the same
}

bool Date::valid_check() {
    int days_in_month[] = {31, 29, 31, 30, 31, 30, 31 , 31 , 30, 31 ,30 , 31};
    if (_month  < 1 || _month > 12) {
        print_invalid_dates("month");
        return false;
    }
    if (_day < 1 || _day > days_in_month[_month - 1]) {
        print_invalid_dates("day");
        return false;
    }
    if (_year > 3000 || _year < 2000) {
        print_invalid_dates("year");
        return false;
    }
    return true;
}

void Date::print_invalid_dates(string error_type) {
    cout << "ERROR: invalid " << error_type << " in ";
    cout << setfill('0') << setw(2) << _month << "/";
    cout << setfill('0') << setw(2) << _day << "/";
    cout << setfill('0') << setw(4) << _year << endl;
}