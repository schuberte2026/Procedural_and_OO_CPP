//============================================================================
// Name        : appointments.h - appointments and a schedule (a collection
//               of appointments)
// Author      : Evan Schubert
//============================================================================
#ifndef APPOINTMENTS_H
#define APPOINTMENTS_H
#include <string>

#include "date.h"

// Appointment: store an appointment as a date and a description
class Appointment
{
public:
    Appointment(Date date, std::string description);

    // construct an appointment on 0/0/0 with an empty description
    Appointment() {
        // TODO: add code here - IF NEEDED - to make sure the constructor works
    }

    bool before(Appointment a, Appointment b);

    Date get_date() const { return _date; }

    std::string description() const { return _description; }

    // printable form of appointment
    std::string to_string() const {
        return get_date().to_string() + ": " + _description;
    }



private:
    Date        _date;                // do not change!
    std::string _description;         // do not change!

    std::string remove_white_spaces(const std::string& s);
};

// returns true if a's date is earlier than b's date
bool before(Appointment a, Appointment b);

// Schedule: an ordered list of appointments (ordered by date, with no
//           ordering between appointments on the same date)
class Schedule
{
public:
    Schedule() : num_appointments{0} { }

    // Add an appointment to the list in order by date
    // precondition: num_appointments < MAX_APPOINTMENTS
    void add(Appointment new_appointment);

    int appointment_count() const { return num_appointments; }

    // write appointment list to cout in order, one per line
    //  (in production code the destination would be passed
    //  as a parameter, but we're using cout for simplicity)
    void write_to_cout();

private:
    static const int MAX_APPOINTMENTS = 20;     // do not change!
    int   num_appointments;                     // do not change!
    Appointment appointments[MAX_APPOINTMENTS]; // do not change!
};

#endif //APPOINTMENTS_H
