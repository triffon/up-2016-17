/*
 * higherorder.cpp
 *
 *  Created on: 11.01.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include <cmath>
using namespace std;

typedef int (*nextfun)(int);
typedef double (*mathfun)(double);
typedef double (*mathop)(double, double);

double myplus(double a, double b) {
	return a + b;
}

double mult(double a, double b) {
	return a * b;
}

int plus1(int i) { return i + 1; }

double id(double x) { return x; }

double two(double i) { return 2; }

double X;

double constx(double i) { return X; }


double accumulate
        (mathop op, double base,
		int a, int b,
		mathfun f, nextfun next) {
	double s = base;
	for(int i = a; i <= b; i = next(i))
		s = op(s, f(i));
	return s;
}

long pow2(int n) {
	return accumulate(mult, 1, 1, n, two, plus1);
}

double power(double x, int n) {
	X = x;
	return accumulate(mult, 1, 1, n, constx, plus1);
}

long fact(int n) {
	return accumulate(mult, 1, 1, n, id, plus1);
}

double exponent_term(double i) {
	return power(X, i) / fact(i);
}

double exponent(double x, int n) {
	X = x;
	return accumulate(myplus, 0, 0, n, exponent_term, plus1);
}

long binom(int n, int k) {
	return accumulate(mult, 1, n - k + 1, n, id, plus1)
			/ fact(k);
}

int minusplus(int i) {
	return (i % 2 == 0) ? 1 : -1;
}

double mystery_term(double i) {
	return minusplus(i) * power(X, 2*i + 1) / fact(2*i + 1);
}

double mystery(double x, int n) {
	X = x;
	return accumulate(myplus, 0, 0, n, mystery_term, plus1);
}

mathfun function = NULL;

double const EPS = 1E-10;
double derivative(double x) {
	return (function(x + EPS) - function(x)) / EPS;
}
/*
mathfun derive(mathfun f) {
	function = f;
	return derivative;
}
*/

auto derive(mathfun f) {
	return [f](double x) { return (f(x + EPS) - f(x)) / EPS; };
}

int main() {
	cout << fact(7) << endl;
	cout << power(3, 5) << endl;
	cout << exponent(1, 10) << endl;
	cout << binom(5, 2) << endl;
	cout << mystery(3.14 / 2, 10) << endl;
	auto mycos = derive(sin);
	cout << mycos(0) << endl;
	auto minussin = derive(cos);
	cout << minussin(3.14 / 2) << ' ' << mycos(0) << endl;
	cout << exp(1) << ' ' << derive(exp)(1) << endl;
	return 0;
}


