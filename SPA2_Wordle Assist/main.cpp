// SPA 2, Fall 2024, Evan Schubert
#include <iostream>
#include <cassert>

const int MAX_SIZE = 3000;
using std::string;
using std::cout;
using std::endl;
using std::cin;

bool can_match(const string& possible_answer, const string& guess, const string& letter_matches);

bool check_exact_match(const string& possible_answer, const string& guess, int index_to_check);

bool check_no_match(const string& possible_answer, const char& c);

bool check_misplaced_match(const string& possible_answer, const string& guess, size_t index_to_check);

void run_checks();

void read_data();

bool iterate_letter_matches(const string& possible_answer, const string& guess, const string& letter_matches);

bool check_letter_matches(const string& possible_answer, const string& guess, const string& letter_matches, size_t i);

void read_possible_answers(string possible_answers[]);

int read_possible_guesses_and_letter_matches(string guesses[], string letter_matches[], int guess_count);

//void print_possible_guesses(std::string* possible_guesses, int pg_size, std::string* possible_answers, int pa_size);
void print_guesses(string guesses[], int guess_count);

void print_possible_guesses(string possible_guesses[], int num_guesses);


int main() {
    run_checks();
    read_data();
    return 0;
}

void run_checks() {
    assert( can_match("abcde", "axbxf", ".-\?--"));
    assert(!can_match("abcde", "axbxd", ".-\?--"));
    assert( can_match("abcde", "easty", "\?\?---"));
    assert(!can_match("abcde", "abcdf", "....."));
    assert( can_match("abcde", "uvwxy", "-----"));
}

void read_data() {
    string possible_answers[MAX_SIZE];
    string guesses[MAX_SIZE];
    string letter_matches[MAX_SIZE];
    string possible_guesses[MAX_SIZE];
    string word;
    int num_guesses = 0;
    int guess_count = 0;

    //reads in words from file until "END" occurs, then it breaks out of while loop
    read_possible_answers(possible_answers);


    // possible_answers: all words before "END"
    // guesses after "END"
    // letter_matches after "END"
    guess_count = read_possible_guesses_and_letter_matches(guesses, letter_matches, guess_count);

    int k = 0;

    for (const string& anAnswer: possible_answers) {
        if (anAnswer.empty()) {
            break; //no more possible answers
        }

        bool valid_word = true;
        int z = 0;

        for(const string& aGuess: guesses) {
            if (aGuess.empty()) {
                break; //no more guesses
            }
            if(!can_match(anAnswer, aGuess, letter_matches[z])) {
                valid_word = false;
                break;
            }
            z++;
        }
        if (valid_word) {
            possible_guesses[k] = anAnswer;
            k++;
            num_guesses++;
        }

    }

    print_guesses(guesses, guess_count);
    print_possible_guesses(possible_guesses, num_guesses);
}

void read_possible_answers(string possible_answers[]) {
    string word;
    int i = 0;
    while (cin >> word && word != "END") {
        possible_answers[i] = word;
        i++;
    }
}

int read_possible_guesses_and_letter_matches(string guesses[], string letter_matches[], int guess_count) {
    string word;
    int j = 0;
    while (cin >> word ) {
        guesses[j] = word; //takes in next line as a "guess"
        guess_count++;
        cin >> word; // assumes that there will be letter match as next line
        letter_matches[j] = word;
        j++;
    }
    return guess_count;
}





// (.) letter in guess matches letter in real word
// (-) letter in guess not in real word
// (?) letter appears in real world, but not at the guessed position
bool can_match(const string& possible_answer, const string& guess, const string& letter_matches) {
    const bool result = iterate_letter_matches(possible_answer, guess, letter_matches);
    return result;
}

bool iterate_letter_matches(const string& possible_answer, const string& guess, const string& letter_matches) {
    for (size_t i = 0; i < letter_matches.size(); i++) {
        if(!check_letter_matches(possible_answer, guess, letter_matches, i)) {
            return false;
        }
    }
    return true;
}

bool check_letter_matches(const string& possible_answer, const string& guess, const string& letter_matches, size_t i) {
    switch (letter_matches[i]) {
        case '.':
            return check_exact_match(possible_answer, guess, i);
        case '-':
            return check_no_match(possible_answer, guess[i]);
        case '?':
            return check_misplaced_match(possible_answer, guess, i);
        default:
            return false;
    }
}


bool check_exact_match(const string& possible_answer, const string& guess, int index_to_check) {
    //checks if guess character matches character in same position in possible_answer
    const char pa_char = possible_answer[index_to_check];
    const char g_char = guess[index_to_check];

    if (pa_char != g_char) { //wasn't exact match between guess and possible_answer
        return false;
    }
    return true;
}

bool check_no_match(const string& possible_answer, const char& c) {
    //checks if guess character is not contained in possible_answer
    //returns whether the character from the guess word is in possible_answer
    return possible_answer.find(c) == string::npos;
}

bool check_misplaced_match(const string& possible_answer, const string& guess, size_t index_to_check) {
    //checks if guess character appears in possible_answer, but the position guessed wasn't correct
    char g_char = guess[index_to_check];

    for (size_t i = 0; i < possible_answer.size(); i++) {
        //returns true if the character in guess is in possible_answer, but the user didn't guess the correct position
        if (i != index_to_check && possible_answer[i] == g_char) {
            return true;
        }
    }
    return false;
}



void print_guesses(string guesses[], const int guess_count) {
    int cur_index = 0;
    cout << "Possible guesses after ";
    for (int i = 0; i < guess_count; i++) {
        if(!guesses[i].empty()) {
            cout << guesses[i];
            cur_index++;

            if (cur_index < guess_count) {
                cout << ", ";
            }
        }
    }
}

void print_possible_guesses(string possible_guesses[], int num_guesses) {
    cout << ": " << num_guesses << endl;
    for (int i = 0; i < num_guesses; i++) {
        if(!possible_guesses[i].empty()) {
            cout << possible_guesses[i] << endl;
        }
    }
}


