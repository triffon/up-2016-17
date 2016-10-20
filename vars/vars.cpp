/*
 * hello.cpp
 *
 *  Created on: 5.10.2016 г.
 *      Author: trifon
 */

#include <iostream>
#include <cmath>
using namespace std;

int hello () {
  const int N = 5;
  cout << N;
  // !!! cin >> N;
  double a = 5;
  cout << "a = " << a << endl ;
  cout << "2a = " << 2 * a << endl ;
  int b = 15;
  cin >> a >> b;
  int c = a + b;
  cout << a << '+' << b << '+' << c << " = " << a + b + c << endl;
  int d = 1;
  cin >> d;
  cout << "d = " << d;
  // !!! cout << "1" * 2 << endl;
  return 0;
}

int bools() {
	bool isItRaining = true, isItCold = false, goToPicnic;
	// isItRaining = false;
	goToPicnic = !isItRaining && !isItCold;
	goToPicnic = !(isItCold || isItRaining);
	cout << "Ще ходим ли на\nпикник?  \t" << goToPicnic << endl;
	bool dontCare;
	cin >> dontCare;
	goToPicnic = !isItRaining && !isItCold || dontCare;
	cout << "Ще ходим ли на пикник сега?\t" << goToPicnic << endl;
	// !!! cout << 'abc' << endl;
	return 0;
}

int ints() {
	long egn = 9512058274;
	cout << egn << endl;
	unsigned x = 5;
	// !!! x = x - 10;
	cout << x << endl;
	int a = 15;
	int b = 9;
	cout << a / b << ' ' << a % b << endl;
	cout << -a << endl;
	// !!! (cout << a) < (b << endl);
	cout << (a < b) << endl;
	cout << ((a > b) > x) << endl;
}

int floats() {
	// !!! float y = 1e-100;
	double y = 1e-200;
	cout << y << endl;
	y = y * y;
	cout << y << endl;
	cout << (y == 0) << endl << endl;

	const float EPS = 1E-3;

	float z = 1.2;
	float t = z * 0.3;
	t = t * 0.3;
	t = t / 0.9;
	cout << (z == t) << endl;
	cout << (fabs(z-t) < EPS) << endl << endl;
//	z = z - 0.3;
	z -= 0.3;
	z = z - 0.6;
	z = z - 0.3;
	cout << z << endl;
	cout << (z == 0) << endl;
	cout << (fabs(z) < EPS) << endl;
}

int main() {
	short s = 100;
	long egn = 9876543210;
	(((cout) << ((s) + (egn))) << endl);
	2+3;
	bool b = true;
	char c = 'A';
	cout << (char)(b + c) << endl;
	double d = s + 0.3;// pow(s,100);
	cout << d << endl;
	short s2 = (short)d;
	cout << s2 << endl;
	// !!! cout << s / 3 << endl;
	cout << s / 3.0 << endl;

	char digit;
	cout << "Въведете цифра: ";
	cin >> digit;

	int digitNumber = digit - '0';
	cout << "Удвоената цифра: " << digitNumber * 2 << endl;
	// !!! cout << digitNumber + 1 < 10 << endl;
	// !!! (cout << (digitNumber + 1)) < (10 << endl);
	cout << (digitNumber + 1 < 10) << endl;
	cout << ((-s)-5) << endl;
	{}{};;;;{}{{}{}{}{}}
	s = 1.3;
	cout << s << endl;
;;;;;
	cout << ++s << endl; // Връща s, lvalue
	cout << s++ << endl; // връща старата стойност на s, rvalue
	cout << s << endl;
	{}{}{}{}{}
	(++s) += 5;
	cout << s << endl;

	// !!! (s++) += 5
	// !!! s++ + ++s;
}


