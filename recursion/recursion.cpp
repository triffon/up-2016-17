/*
 * recursion.cpp
 *
 *  Created on: 21.12.2016 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

int fact(int n) {
	if (n == 0)
		return 1;
	return n * fact(n-1);
}

int main() {
	cout << fact(7) << endl;
	return 0;
}


