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

double X[3], Y[3];

double enterCoordinate(char xory, int index) {
	cout << xory << index << " = ";
	double coordinate;
	cin >> coordinate;
	return coordinate;
}

void enterTriangle() {
	for(int i = 0; i < 3; i++) {
		X[i] = enterCoordinate('x',i + 1);
		Y[i] = enterCoordinate('y',i + 1);
	}
}

double calculateTriangleArea() {
	// Ще използваме Хероновата формула
	double sides[3];
	int k = 0;
	for(int i = 0; i < 3; i++)
		for(int j = i + 1; j < 3; j++)
			sides[k++] = distance(X[i], Y[i], X[j], Y[j]);
	return heron(sides[0], sides[1], sides[2]);
}

void printTriangleArea() {
	cout << "S = " << calculateTriangleArea() << endl;
}

double distance(double x1, double y1, double x2, double y2) {
	return sqrt(square(x1 - x2) + square(y1 - y2));
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

int maintest() {
	enterTriangle();
	printTriangleArea();
	return 0;
}




