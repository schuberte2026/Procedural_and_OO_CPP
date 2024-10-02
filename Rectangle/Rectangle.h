//
// Created by schuberte on 10/2/2024.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
    public:
    Rectangle(double length, double width);
    double calculateArea() const;

    private:
    double rectLength;
    double rectWidth;

};

#endif //RECTANGLE_H
