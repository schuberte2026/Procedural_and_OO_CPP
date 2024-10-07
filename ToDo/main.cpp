#include <iostream>
#include "ToDo.h"

int main() {
    ToDo today("Eat breakfast."); // can't start a day without eating!
    today.add("Go to class.");
    today.add("Eat lunch.");
    today.add("Show up for office hours.");
    today.add("Go home.");
    std::cout << "Second added: " << today[1] << std::endl;
    std::cout << "Today's list:" << std::endl;
    while ( !today.empty() )
        std::cout << today.next_item() << std::endl;
    return 0;
}