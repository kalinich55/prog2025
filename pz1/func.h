#ifndef FUNC_H
#define FUNC_H

#include "structs.h"

Point readPoint();
void writePoint(Point p);

Circle readCircle();
void writeCircle(Circle c);
double circlePerimeter(Circle c);
double circleSurface(Circle c);

Square readSquare();
void writeSquare(Square s);
double squarePerimeter(Square s);
double squareSurface(Square s);

bool insideCircle(Point p, Circle c);
bool insideSquare(Point p, Square s);

bool onCircle(Point p, Circle c);
bool onSquare(Point p, Square s);

bool circlesCross(Circle c1, Circle c2);
bool squaresCross(Square s1, Square s2);
bool circleSquareCross(Circle c, Square s);

bool circleInCircle(Circle small, Circle big);
bool squareInSquare(Square small, Square big);
bool squareInCircle(Square s, Circle c);
bool circleInSquare(Circle c, Square s);

#endif