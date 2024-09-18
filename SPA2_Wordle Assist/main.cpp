// SPA 2, Fall 2024, Evan Schubert
#include <iostream>
#include <cassert>

using std::string;

bool can_match(string possible_answer, string guess, string letter_matches);

void run_checks();

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

bool can_match(string possible_answer, string guess, string letter_matches) {
    return false;
}
