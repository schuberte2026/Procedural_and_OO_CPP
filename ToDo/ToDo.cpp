#include <iostream>
#include <string>
#include "ToDo.h"
using namespace std;

ToDo::ToDo() : count{0} { } //Default Constructor

ToDo::ToDo(string first_item) : count{1} { //Parameterized constructor
    items[0] = first_item;
}

bool ToDo::empty() {
    return count <= 0;
}

bool ToDo::full() {
    return count >= MAXITEMS;
}

void ToDo::add(string next_item) {
    if ( full() )
        throw "Adding item to full todo list.";
    items[count] = next_item;
    ++count;
}

string ToDo::next_item() {
    if ( empty() )
        throw "Removing item from empty todo list.";
    string result = items[0];
    for(int i = 0; i < count - 1; ++i)
        items[i] = items[i + 1];
    --count;
    return result;
}

// returns the next item capitalized; this is to illustrate converting
//   a string to upper case; use tolower to convert to lower case.
string ToDo::next_item_capitalized() {
    string item = next_item();
    // note use of size_t to initialize i; this avoids warnings when
    //   comparing i to item.length() (since item.length() is generally unsigned)
    for(size_t i = 0; i < item.length(); ++i)
        item[i] = toupper(item[i]);
    return item;
}

string ToDo::operator[](int ix) {
    if ( ix < 0 || ix >= count )
        throw "Accessing non-existance item";
    return items[ix];
}
