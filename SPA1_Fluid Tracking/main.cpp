// SPA 1, Fall 2024, Evan Schubert

#include <fstream>
#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int total_mL = 0; // keeps a count of the total differential of mL for the patient

int check_differential(const string& time, const string& item) {
    //this method checks if the differential is large enough to notify
    if (total_mL >= 1000) {
        cout << "after consuming " << item << " at " << time << ", intake exceeds output by " << total_mL << " ml" << endl;
    }
    return 0;
}

int check_measurement(const string& item, const int amt_mL, const string& time) {
    //this method checks which type of measurement occured
    if (item == "urine" || item == "bloodloss" || item == "diarrhea") {
        total_mL -= amt_mL;
    } else {
        total_mL += amt_mL;
        check_differential(time, item);
    }
    return 0;
}


int main() {
    string time;
    string item;
    int amt_mL = 0;

    while (cin >> time) {
        cin >> item >> amt_mL;
        check_measurement(item, amt_mL, time);

    }

    cout << "the final fluid differential is " << total_mL << " ml" << endl;

    return 0;
}
