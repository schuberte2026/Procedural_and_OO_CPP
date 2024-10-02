#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(const double length, const double width) {
    rectLength = length;
    rectWidth = width;
}

double Rectangle::calculateArea() const {
    return rectLength * rectWidth;
}

int main() {
    Rectangle rect = Rectangle(3, 4);
    std::cout << rect.calculateArea() << std::endl;
}


