#include <iostream>
#include "func.h"
using namespace std;

int main() {
    cout << "Enter point (x y): ";
    Point p = readPoint();
    cout << "Point: ";
    writePoint(p);
    cout << endl;

    cout << "Enter circle (center_x center_y radius): ";
    Circle c = readCircle();
    cout << "Circle: ";
    writeCircle(c);
    cout << endl;
    cout << "Circle length: " << circlePerimeter(c) << endl;
    cout << "Circle area: " << circleSurface(c) << endl;

    cout << "Enter square (topLeft_x topLeft_y side): ";
    Square s = readSquare();
    cout << "Square: ";
    writeSquare(s);
    cout << endl;
    cout << "Square perimeter: " << squarePerimeter(s) << endl;
    cout << "Square area: " << squareSurface(s) << endl;

    cout << "Point in circle: " << insideCircle(p, c) << endl;
    cout << "Point in square: " << insideSquare(p, s) << endl;
    cout << "Point on circle: " << onCircle(p, c) << endl;
    cout << "Point on square: " << onSquare(p, s) << endl;

    cout << "Circle and square cross: " << circleSquareCross(c, s) << endl;
    cout << "Circle in square: " << circleInSquare(c, s) << endl;
    cout << "Square in circle: " << squareInCircle(s, c) << endl;

    return 0;
}