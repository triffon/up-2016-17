/*
 * bitwise.cpp
 *
 *  Created on: 7.12.2016 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;
int main() {
	unsigned long a = 42, b = 163, c = ~a;
	cout << (a ^ b) << endl;
	cout << c << endl;
	unsigned long x = 42;
	for(int i = 0; i < 64; i++) {
		cout << x << endl;
		x <<= 1;
	}
	cout << "Вторият бит на " << a << " е "
			<< ((a & 4) != 0) << endl;
	a |= 4;
	cout << "Вторият бит на " << a << " е "
			<< ((a & 4) != 0) << endl;
	a |= 4;
	cout << "Вторият бит на " << a << " е "
			<< ((a & 4) != 0) << endl;

	return 0;
}


