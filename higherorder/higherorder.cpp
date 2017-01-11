/*
 * higherorder.cpp
 *
 *  Created on: 11.01.2017 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

typedef int (*nextfun)(int);
typedef double (*mathfun)(double);
typedef double (*mathop)(double, double);

double accumulate
        (mathop op, double base,
		int a, int b,
		mathfun f, nextfun next) {
	double s = base;
	for(int i = a; i <= b; i = next(i))
		s = op(s, f(i));
	return s;
}

double mult(double a, double b) {
	return a * b;
}

int plus1(int i) { return i + 1; }

double id(double x) { return x; }

long fact(int n) {
	return
accumulate(mult, 1, 1, n, id, plus1);
}

int main() {
	cout << fact(7) << endl;
	return 0;
}


