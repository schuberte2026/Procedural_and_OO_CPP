#include <iostream>
#include <sstream>
using namespace std;
//declare methods before main, can implement them before or after main
int add(int a, int b);

int add(int a, int b = 2) { //can give default values when passing in params, must exclude this when calling method, otherwise youll overrride the default value
    int sum = a + b;
    return sum;
}

constexpr int run_time() {
    int a = 0;
    cout << "Enter a number: " << endl;
    cin >> a;
    return a;
}

void printArray(int arr[], int size) {
    int anotherVar = 5; // local scope and automatic lifetime
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}
int globVar = 30; // Global scope and static lifetime

int main() {
    // //takes in multiple words in a string
    // string input;
    // cout << "Please enter a string: ";
    // getline(cin, input);
    // cout << endl << input << endl;


    string first, last;
    int age = 0;

    //can utilize this for file i/o
    while (cin >> first) {
        cout << "Enter age: " << endl;
        if (first == "exit") break;
        cin >> last >> age;
        cout << "First: " << first << " Last: " << last << " Age: " << age << endl;
    }

    /*
     *Basic data types
     */
    //Primitive
    //int num = 0;
    // float num2 = 0.0;
    // double num3 = 0.0;
    // char a = 65;
    // bool b = true;
    // wchar_t c = 120;
    // //data type info: c++ (https://en.cppreference.com/w/c/language/type)
    // const int CONST_INT = 10; //makes a constant (final in java) var
    //
    //
    // cout << "Size of " << a << " is " << sizeof(a) << " bytes" << endl;
    //
    // //converting data types
    // float pi = 3.14;
    // //another option
    // int intPI = (int) pi;
    // //another option
    // int intPI2 = static_cast<int>(pi); //better for c++
    //
    // //c++ short circuits similar to java
    //
    // //pre/post incrementing
    // int x = 5;
    //
    // int y = x++;
    // cout << y << endl;
    // int z = ++x;
    // cout << z << endl;
    //
    // //string .length()/.size(), s[], .at(), .append, to_string(i), .substr(0,5)
    //
    // cout << int(pi) << endl;
    //
    //
    // //testing string methods
    // string first_name = "John";
    // cout << first_name.at(0) << endl;
    //
    // //adding two strings
    // string last_name = "Doe";
    // string name = first_name + " " + last_name;
    //
    // string h = "hello ";
    // //h += " world"; //or
    // h.append(name);
    //
    // //convert string to int
    // stoi("12");
    // //convert string to double
    // stod("12.5");
    //
    // cout << h << endl;
    //
    // int xz = 10;
    //
    // //need to convert num to string when concencatnnating
    // cout << name + to_string(xz) << endl;
    //
    // //name = "John Doe"
    // string first = name.substr(0, 4); //second param is how many characters you want
    // cout << first << endl;
    //
    // cout << add(1) << endl;
    // cout << add(1, 2, 3) << endl;

    //if-else statements
    int a = 5;
    int b = 10;

    if (a) { //as long as value is not 0, it remains true
        cout << "Non-zero" << endl;
    }

    int max = a > b ? a : b; //equilvalent to the code block below
    if (a > b) {
        max = a;
    } else {
        max = b;
    }

    // //if else ladder
    // if (a) {
    //
    // } else if (a) {
    //
    // } else

    // switch (a) {
    //     case 1:
    //         cout << "1" << endl;
    //         break;
    //     case 2:
    //         cout << "2" << endl;
    //         break;
    //     default:
    //         cout << "Otherwise unknown" << endl;
    // }

    // //loops (for loops, while loops, do while loops)
    // int i = 10;
    // do {
    //     cout << "hello " + to_string(i) << endl;
    //     i--;
    // } while (i); // or i > 0
    //
    // string test = "test";
    // for (int i = 0; i < test.length(); i++) {
    //     cout << test[i];
    // }
    // cout << endl;
    // for (int i =0, j = 10; i < j; i++, j--) {
    //     cout << "i = " << i << "j= " << j << endl;
    // }

    //cout << max << endl;

    string name = "John";

    // for(char c: name) {
    //     cout << c << endl;
    // }
    //dont have .split so let's use this
    //break destroys loop, continue skips instructions below (continues the loop though)
    // string line = "This is a line";
    // istringstream stream(line);
    // string word;
    // while(stream >> word) {
    //     cout << word << endl;
    //
    //     if(word == name) {
    //         break;
    //     }
    // }

    // int i = 5; //copy
    // int j {5}; //brace/list another way to initialize, ensures value matches data type
    // auto k = 5; //don't have to specify type of data, similar to var

    //how to make a constant
    //const int NUM = run_time();
    //can do runtime initialize
    //cout << NUM << endl;
    //can do another way to make
    //constexpr  int NUM = run_time(); //makes it so you can't assign it during run time, only during compile time

    //compile time: involves code analysis, type checking ,optimization, generation executables
    //dynamic behavior: involves executing coding , dynamic memory, input/out

    //arrays
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //cannot change the size
    cout << arr[0] << endl;

    //cout << NUM << endl;

    int nums[5] = {1,2,3,4,5}; //assigns 0 to empty values
    cout << nums[0] << endl;
    nums[0] = 42;
    cout << nums[0] << endl;

    for (int i = 0; i < 5; i++) {
        cout << nums[i] << endl;
    }

    //cannot make a function inside the main function

    printArray(nums, 5);
    return 0;
}

int add(int&a, int&b) { //adding the & symbol means: passing by reference, more efficient
    int sum = a + b;
    a++;
    return sum;
}
