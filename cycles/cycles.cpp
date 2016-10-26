/*
 * cycles.cpp
 *
 *  Created on: 26.10.2016 г.
 *      Author: trifon
 */

#include <iostream>
#include <cmath>
using namespace std;

int fact() {
	int n;
	cout << "n = ";cin >> n;
	int f = 1;
	for(int i = 1; i <= n; i++)
		f *= i;
	cout << n << "! = " << f << endl;
}

int expx() {
	int n;
	double x, sum = 0;
	cout << "n = ";cin >> n;
	cout << "x = ";cin >> x;
	for(int i = 0; i <= n; i++) {

		unsigned long f = 1;
		for(int j = 1; j <= i; j++)
			f *= j;

		sum += pow(x, i) / f;
	}
	cout << "sum = " << sum << endl;
	return 0;
}

int div3() {
	int n;
	cout << "n = ";cin >> n;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		int xi = n*n*n + 5*i*i*n - 8*i;
		if (xi % 3 == 0)
			count++;
	}
	cout << "Числата кратни на 3 са " << count << endl;
}

int maxx() {
	int n;
	cout << "n = ";cin >> n;
	int max = n*n*n + 5*n - 8;
	int maxi = 1;
	for (int i = 2; i <= n; i++) {
		int xi = n*n*n + 5*i*i*n - 8*i;
		if (xi > max) {
			max = xi;
			maxi = i;
		}
	}
	cout << "Най-голямото число е " << max << endl;
	cout << "Постига се при i = " << maxi << endl;
}

int syracuze() {
	int n;
	cout << "Въведете n: ";cin >> n;
	int i = 0;
	while (n > 1) {
	  if (n % 2 == 0) n /= 2;
	  else           (n *= 3)++;
	  cout << "n = " << n << endl;
	  i++;
	}
	cout << "Направени " << i << " стъпки" << endl;
}

int fact2() {
	int n;
	cout << "Въведете n: ";cin >> n;
	long f = 1;
	int i = 1;
	while (i <= n)
		f *= i++;
	cout << n << "! = " << f << endl;
}

int avg() {
	double x = 1, sum = 0;
	int n = 0;
	while (x != 0) {
		cout << "x = ";cin >> x;
		sum += x;
		n++;
	}
	cout << "Средното аритметично е " << sum / (--n) << endl;
}

int main() {
	double x, sum = 0, eps;
	cout << "x = ";cin >> x;
	cout << "eps = ";cin >> eps;
	int i = 0;
	double yi = eps;
	while (fabs(yi) >= eps) {

		unsigned long f = 1;
		for(int j = 1; j <= i; j++)
			f *= j;

		sum += (yi = pow(x, i) / f);
		i++;
	}
	cout << "sum = " << sum << endl;
	return 0;
}
