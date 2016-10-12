/*
 * hello.cpp
 *
 *  Created on: 5.10.2016 г.
 *      Author: trifon
 */

#include <iostream>
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

int main() {
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
	// !!! float y = 1e-100;
	double y = 1e-100;
	y = y * y;
	cout << y << endl;
	cout << (y == 0) << endl;
}


