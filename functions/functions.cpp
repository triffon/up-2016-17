/*
 * functions.cpp
 *
 *  Created on: 9.11.2016 г.
 *      Author: trifon
 */

#include <iostream>
#include <cmath>

#include "functions.h"
using namespace std;

/*
double heron(double, double, double) {
	return 0;
}
*/

double f(int x) {
	// x = 5.6;
	// Реално: x = 5;
	return sqrt(x) + 5;
	cout << "Hello!\n";
}

int testf() {
	// y = 7.xxxxx
	// y = 7
	int y = f(5.6);
	cout << y << endl;
	cout << f(5.6) << endl;
}

double X1, Y1, X2, Y2, X3, Y3;

double enterCoordinate(char xory, int index) {
	cout << xory << index << " = ";
	double coordinate;
	cin >> coordinate;
	return coordinate;
}

void enterTriangle() {
	X1 = enterCoordinate('x',1);
	Y1 = enterCoordinate('y',1);
	X2 = enterCoordinate('x',2);
	Y2 = enterCoordinate('y',2);
	X3 = enterCoordinate('x',3);
	Y3 = enterCoordinate('y',3);
}

double calculateTriangleArea() {
	// Ще използваме Хероновата формула
	double a = distance(X1, Y1, X2, Y2);
	double b = distance(X2, Y2, X3, Y3);
	double c = distance(X1, Y1, X3, Y3);
	return heron(a, b, c);
}

void printTriangleArea() {
	cout << "S = " << calculateTriangleArea() << endl;
}

double distance(double x1, double y1, double x2, double y2) {
	return sqrt(square(x1 - y1) + square(x2 - y2));
}

double square(double x) {
	return x * x;
}

double heron(double a, double b, double c) {
	// S = sqrt(p*(p-a)*(p-b)*(p-c))
	double p = semiPerimeter(a, b, c);
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

double semiPerimeter(double a, double b, double c) {
	return (a + b + c) / 2;
}

int main() {
	enterTriangle();
	printTriangleArea();
	return 0;
}


