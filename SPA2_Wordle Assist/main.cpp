// SPA 2, Fall 2024, Evan Schubert
#include <iostream>
#include <cassert>

const int MAX_SIZE = 3000;
using std::string;
using std::cout;
using std::endl;

bool can_match(const string& possible_answer, const string& guess, const string& letter_matches);

bool check_exact_match(const string& possible_answer, const string& guess, int index_to_check);

bool check_no_occurence(const string& possible_answer, const string& guess, int index_to_check);

bool check_misplaced_match(const string& possible_answer, const string& guess, int index_to_check);

void run_checks();

bool iterate_letter_matches(const string& possible_answer, const string& guess, const string& letter_matches);

int main() {
    run_checks();
    return 0;
}

void run_checks() {
    assert( can_match("abcde", "axbxf", ".-\?--"));
    assert(!can_match("abcde", "axbxd", ".-\?--"));
    assert( can_match("abcde", "easty", "\?\?---"));
    assert(!can_match("abcde", "abcdf", "....."));
    assert( can_match("abcde", "uvwxy", "-----"));
}

// (.) letter in guess matches letter in real word
// (-) letter in guess not in real word
// (?) letter appears in real world, but not at the guessed position
bool can_match(const string& possible_answer, const string& guess, const string& letter_matches) {
    iterate_letter_matches(possible_answer, guess, letter_matches);
    return false;
}

bool iterate_letter_matches(const string& possible_answer, const string& guess, const string& letter_matches) {
    bool ret_bool = true;
    for (int i = 0; i < letter_matches.size(); i++) {
        if (letter_matches[i] == '.') {
            //call helper method to check letter guess matches real world letter/position
            check_no_occurence(possible_answer, guess, i);
        }
        else if (letter_matches[i] == '-') {
            //call helper method to check that letter guess matches that it's not in word
            check_no_occurence(possible_answer, guess, i);
        }
        else if (letter_matches[i] == '?') {
            //call helper method to check that letter guess matches that letter appears in real world, but not in guessed position etc
            check_misplaced_match(possible_answer, guess, i);
        }

    }
    return ret_bool;
}


void print_possible_guesses(std::string* possible_guesses, int pg_size, std::string* possible_answers, int pa_size) {
    cout << "Possible guesses after : 0" << endl;
    // cout << "Possible guesses after ";
    // for (int i = 0; i < pg_size; i++) {
    //     cout << possible_guesses[i] << ", ";
    // }
    // cout << ": " << pa_size << std::endl;
    // for (int i = 0; i < pa_size; i++) {
    //     cout << possible_answers[i] << endl;
    // }
}
