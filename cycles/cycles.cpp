/*
 * cycles.cpp
 *
 *  Created on: 26.10.2016 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

int fact() {
	int n;
	cout << "n = ";cin >> n;
	int f = 1;
	for(int i = 1; i <= n; i++)
		f *= i;
	cout << n << "! = " << f << endl;
}

int main() {
	return 0;
}


