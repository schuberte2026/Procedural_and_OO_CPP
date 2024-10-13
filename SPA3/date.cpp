//============================================================================
// Name        : date.cpp
// Author      : Evan Schubert
//============================================================================

//
// Make no changes to this file other than the TODOs below
//

#include "date.h"

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
    if ( _month < 10 )
        formatted << "0";
    formatted << _month << "/";
    if ( _day < 10 )
        formatted << "0";
    formatted << _day << "/" << _year;

    return formatted.str();
}

bool Date::earlier(Date d1, Date d2)
{
    // TODO: implement this; d1 is earlier than d2 if d1's year is earlier.
    //       If the years are the same, check months, and if the months
    //       are the same check the days. DONE
    if (d1.year() < d2.year()) {
        return true;
    } else if (d1.year() > d2.year()) {
        return false;
    }

    //continues if years were the same
    if (d1.month() < d2.month()) {
        return true;
    } else if (d1.month() > d2.month()) {
        return false;
    }

    //continues if months were the same
    if (d1.day () < d2.day ()) {
        return true;
    } else if (d1.day () > d2.day ()) {
        return false;
    }

    //both dates are the same
    return false;
}

// TODO: if useful to your design, add code to check for valid dates
bool Date::valid_check() {
    if (_month  < 1 || _month > 12) {
        print_invalid_dates("month");
        return false;
    }
    if ((_month == 1 || _month == 3 || _month == 5 || _month == 7 ||
        _month == 8 || _month == 10 || _month == 12) && _day > 31) {
        print_invalid_dates("day");
        return false;
        }
    if ((_month == 4 || _month == 6 || _month == 9 || _month == 11) && _day > 30) {
        print_invalid_dates("day");
        return false;
    }
    if (_month  == 2 && _day > 29) {
        print_invalid_dates("day");
        return false;
    } if (_day == 0) {
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
    std::string month_str = std::to_string(_month);
    std::string day_str = std::to_string(_day);
    std::string year_str = std::to_string(_year);
    if (month_str.length() < 2) {
        month_str = "0" + month_str;
    }
    if (day_str.length() < 2) {
        day_str = "0" + day_str;
    }
    if (year_str.length() < 4) {
        for (int i = year_str.length(); i < 4; i++) {
            year_str = "0" + year_str;
        }
    }
    std::cout << "ERROR: invalid " << error_type << " in " << month_str << "/" << day_str << "/" << year_str << std::endl;
}