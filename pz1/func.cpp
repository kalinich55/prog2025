#include "func.h"
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const double EPS = 0.00001;
const double PI_NUM = 3.141592653;

bool sameDouble(double a, double b) {
    return fabs(a - b) < EPS;
}

bool leqDouble(double a, double b) {
    return a < b || sameDouble(a, b);
}

bool geqDouble(double a, double b) {
    return a > b || sameDouble(a, b);
}

Point readPoint() {
    Point p;
    cin >> p.x >> p.y;
    return p;
}

void writePoint(Point p) {
    cout << "(" << p.x << ", " << p.y << ")";
}

Circle readCircle() {
    Circle c;
    cin >> c.center.x >> c.center.y >> c.radius;
    return c;
}

void writeCircle(Circle c) {
    cout << "Circle at (" << c.center.x << ", " << c.center.y << ") with radius " << c.radius;
}

double circlePerimeter(Circle c) {
    return 2 * PI_NUM * c.radius;
}

double circleSurface(Circle c) {
    return PI_NUM * c.radius * c.radius;
}

Square readSquare() {
    Square s;
    cin >> s.topLeft.x >> s.topLeft.y >> s.side;
    return s;
}

void writeSquare(Square s) {
    cout << "Square at (" << s.topLeft.x << ", " << s.topLeft.y << ") with side " << s.side;
}

double squarePerimeter(Square s) {
    return 4 * s.side;
}

double squareSurface(Square s) {
    return s.side * s.side;
}

bool insideCircle(Point p, Circle c) {
    double diffX = p.x - c.center.x;
    double diffY = p.y - c.center.y;
    double dist2 = diffX * diffX + diffY * diffY;
    return dist2 < c.radius * c.radius - EPS;
}

bool insideSquare(Point p, Square s) {
    bool goodX = p.x > s.topLeft.x + EPS && p.x < s.topLeft.x + s.side - EPS;
    bool goodY = p.y < s.topLeft.y - EPS && p.y > s.topLeft.y - s.side + EPS;
    return goodX && goodY;
}

bool onCircle(Point p, Circle c) {
    double diffX = p.x - c.center.x;
    double diffY = p.y - c.center.y;
    double dist2 = diffX * diffX + diffY * diffY;
    return sameDouble(dist2, c.radius * c.radius);
}

bool onSquare(Point p, Square s) {
    bool leftRight = (sameDouble(p.x, s.topLeft.x) || sameDouble(p.x, s.topLeft.x + s.side)) &&
                     leqDouble(p.y, s.topLeft.y) && geqDouble(p.y, s.topLeft.y - s.side);
    
    bool topBottom = (sameDouble(p.y, s.topLeft.y) || sameDouble(p.y, s.topLeft.y - s.side)) &&
                     leqDouble(p.x, s.topLeft.x + s.side) && geqDouble(p.x, s.topLeft.x);
    
    return leftRight || topBottom;
}

bool circlesCross(Circle c1, Circle c2) {
    double dx = c1.center.x - c2.center.x;
    double dy = c1.center.y - c2.center.y;
    double dist = sqrt(dx * dx + dy * dy);
    double maxR = c1.radius + c2.radius;
    double minR = fabs(c1.radius - c2.radius);
    return leqDouble(dist, maxR) && geqDouble(dist, minR);
}

bool squaresCross(Square s1, Square s2) {
    bool crossX = s1.topLeft.x < s2.topLeft.x + s2.side + EPS &&
                  s1.topLeft.x + s1.side > s2.topLeft.x - EPS;
    
    bool crossY = s1.topLeft.y > s2.topLeft.y - s2.side - EPS &&
                  s1.topLeft.y - s1.side < s2.topLeft.y + EPS;
    
    return crossX && crossY;
}

bool circleSquareCross(Circle c, Square s) {
    Point corners[4] = {
        {s.topLeft.x, s.topLeft.y},
        {s.topLeft.x + s.side, s.topLeft.y},
        {s.topLeft.x + s.side, s.topLeft.y - s.side},
        {s.topLeft.x, s.topLeft.y - s.side}
    };

    for (int i = 0; i < 4; i++) {
        if (insideCircle(corners[i], c) || onCircle(corners[i], c)) {
            return true;
        }
    }

    if (insideSquare(c.center, s)) {
        return true;
    }

    double nearX = max(s.topLeft.x, min(c.center.x, s.topLeft.x + s.side));
    double nearY = max(s.topLeft.y - s.side, min(c.center.y, s.topLeft.y));
    
    double dx = c.center.x - nearX;
    double dy = c.center.y - nearY;
    double dist2 = dx * dx + dy * dy;
    
    return dist2 <= c.radius * c.radius + EPS;
}

bool circleInCircle(Circle small, Circle big) {
    double dx = small.center.x - big.center.x;
    double dy = small.center.y - big.center.y;
    double dist = sqrt(dx * dx + dy * dy);
    return leqDouble(dist + small.radius, big.radius);
}

bool squareInSquare(Square small, Square big) {
    bool xOk = geqDouble(small.topLeft.x, big.topLeft.x - EPS) &&
               leqDouble(small.topLeft.x + small.side, big.topLeft.x + big.side + EPS);
    
    bool yOk = leqDouble(small.topLeft.y, big.topLeft.y + EPS) &&
               geqDouble(small.topLeft.y - small.side, big.topLeft.y - big.side - EPS);
    
    return xOk && yOk;
}

bool squareInCircle(Square s, Circle c) {
    Point corners[4] = {
        {s.topLeft.x, s.topLeft.y},
        {s.topLeft.x + s.side, s.topLeft.y},
        {s.topLeft.x + s.side, s.topLeft.y - s.side},
        {s.topLeft.x, s.topLeft.y - s.side}
    };

    for (int i = 0; i < 4; i++) {
        double dx = corners[i].x - c.center.x;
        double dy = corners[i].y - c.center.y;
        double dist2 = dx * dx + dy * dy;
        if (dist2 > c.radius * c.radius + EPS) {
            return false;
        }
    }
    return true;
}

bool circleInSquare(Circle c, Square s) {
    bool xOk = c.center.x - c.radius > s.topLeft.x - EPS &&
               c.center.x + c.radius < s.topLeft.x + s.side + EPS;
    
    bool yOk = c.center.y + c.radius < s.topLeft.y + EPS &&
               c.center.y - c.radius > s.topLeft.y - s.side - EPS;
    
    return xOk && yOk;
}