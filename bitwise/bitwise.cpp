/*
 * bitwise.cpp
 *
 *  Created on: 7.12.2016 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

const int BITS = 64;

unsigned long getMask(int i) {
	unsigned long mask = 1;
	return mask << i;
}

bool getBit(unsigned long a, int i) {

	return (a & getMask(i)) != 0;
}

void setBit(unsigned long &a, int i) {
	a |= getMask(i);
}

void resetBit(unsigned long &a, int i) {
	a &= ~getMask(i);
}

void flipBit(unsigned long &a, int i) {
	a ^= getMask(i);
}

void printBits(unsigned long a) {
	for(int i = 0; i < BITS; i++)
		cout << getBit(a, i);
	cout << endl;
}

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

	printBits(b);
	setBit(b, 3);
	printBits(b);
	resetBit(b, 1);
	printBits(b);
	flipBit(b, 2);
	printBits(b);
	flipBit(b, 2);
	printBits(b);

	return 0;
}


