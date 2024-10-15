// SPA 3, Fall 2024, Schubert
//============================================================================
// Name        : appointments.cpp
// Author      : Evan Schubert
//============================================================================

#include "appointments.h"
#include <string>
#include <iostream>

// add other includes as needed here, but appointments.h must be the FIRST include

bool before(Appointment a, Appointment b) {
    return a.get_date().earlier(a.get_date(), b.get_date());
}

Appointment::Appointment(Date date, std::string description) {
    this -> _date = date;
    this-> _description = remove_white_spaces(description);
}

void Schedule::add(Appointment new_appointment)
{
    if(new_appointment.get_date().valid_check()) {
        int pos = 0;

        while(pos < num_appointments  && before(appointments[pos], new_appointment)) {
            ++pos;
        }
        // do not change any of the rest of this method
        for(int i = num_appointments; i > pos; --i)
            appointments[i] = appointments[i - 1];
        if ( pos < num_appointments )
            appointments[pos] = new_appointment;
        else
            appointments[num_appointments] = new_appointment;
        ++num_appointments;
    }
}

void Schedule::write_to_cout() {
    for(int i = 0; i < num_appointments; ++i) {
        std::cout << appointments[i].to_string() << std::endl;
    }
    if (num_appointments == 0) {
        std::cout << "Empty schedule." << std::endl;
    }
}

std::string Appointment::remove_white_spaces(const std::string& s) {
    size_t first = s.find_first_not_of(' ');
    size_t last = s.find_last_not_of(' ');

    return s.substr(first, last - first + 1);
}

