#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int number = 0;
    double result = 0;
    cout << "Enter a number: " << endl;
    cin >> number;
    cout << endl;

    result = number * number * number;
    cout << "The cube of " << number << " is " << result << endl;

    return 0;
}
