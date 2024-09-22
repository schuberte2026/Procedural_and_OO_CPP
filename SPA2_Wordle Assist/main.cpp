// SPA 2, Fall 2024, Evan Schubert
#include <iostream>
#include <cassert>

const int MAX_SIZE = 3000;
using std::string;
using std::cout;
using std::endl;
using std::erase;

bool can_match(const string& possible_answer, const string& guess, const string& letter_matches);

bool check_exact_match(const string& possible_answer, const string& guess, int index_to_check);

bool check_no_match(const string& possible_answer, const char& c);

bool check_misplaced_match(const string& possible_answer, const string& guess, int index_to_check);

void run_checks();

bool iterate_letter_matches(const string& possible_answer, const string& guess, const string& letter_matches);

//void print_possible_guesses(std::string* possible_guesses, int pg_size, std::string* possible_answers, int pa_size);
void print_possible_guesses();

int main() {
    run_checks();
    print_possible_guesses();
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
    const bool result = iterate_letter_matches(possible_answer, guess, letter_matches);
    return result;
}

bool iterate_letter_matches(const string& possible_answer, const string& guess, const string& letter_matches) {
    for (int i = 0; i < letter_matches.size(); i++) {
        if (letter_matches[i] == '.') {
            //checks if guess character matches character in same position in possible_answer
            if(!check_exact_match(possible_answer, guess, i)) {
                return false;
            }
        }
        else if (letter_matches[i] == '-') {
            //checks if guess character is not contained in possible_answer
            if(!check_no_match(possible_answer, guess[i])) {
                return false;
            }
        }
        else if (letter_matches[i] == '?') {
            //checks if guess character appears in possible_answer, but the position guessed wasn't correct
            if(!check_misplaced_match(possible_answer, guess, i)) {
                return false;
            }
        }
    }
    return true;
}

bool check_exact_match(const string& possible_answer, const string& guess, int index_to_check) {
    const char pa_char = possible_answer[index_to_check];
    const char g_char = guess[index_to_check];

    if (pa_char != g_char) { //wasn't exact match between guess and possible_answer
        return false;
    }
    return true;
}

bool check_no_match(const string& possible_answer, const char& c) {
    //returns whether the character from the guess word is in possible_answer
    return possible_answer.find(c) == string::npos;
}

bool check_misplaced_match(const string& possible_answer, const string& guess, int index_to_check) {
    char g_char = guess[index_to_check];

    for (int i = 0; i < possible_answer.size(); i++) {
        //returns true if the character in guess is in possible_answer, but the user didn't guess the correct position
        if (i != index_to_check && possible_answer[i] == g_char) {
            return true;
        }
    }
    return false;
}
/*
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
*/

void print_possible_guesses() {
    cout << "Possible guesses after : 0" << endl;
}

