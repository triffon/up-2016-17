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

int expx_eps() {
	double x, sum = 0, eps;
	cout << "x = ";cin >> x;
	cout << "eps = ";cin >> eps;
	int i = 0;
	double yi;
	do {

		unsigned long f = 1;
		for(int j = 1; j <= i; j++)
			f *= j;

		sum += (yi = pow(x, i) / f);
		i++;
	} while (fabs(yi) >= eps);
	cout << "sum = " << sum << endl;
	return 0;
}

int small_test() {
	int n, sum = 0;
	bool contains5 = false;
	cout << "n = ";cin >> n;
	while (n > 0) {
		sum += n % 10;
		if (n % 10 == 5)
			contains5 = true;
		n /= 10;
	}
	// Ако спрем на n <= 10 в n е останала последната цифра!
	cout << "Сумата на цифрите е " << sum << endl;
	if (contains5)
		cout << "Съдържа цифрата 5\n";
	else
		cout << "Не съдържа цифрата 5\n";
	return 0;

}

int contains5() {
	int n;
	cout << "n = ";cin >> n;
	while (n != 0 && n % 10 != 5)
		n /= 10;
	// !A <-> n == 0 || n % 10 == 5
	// НЕ: n == 0
	// ДА: n % 10 == 5
	if (n != 0)
		cout << "Съдържа цифрата 5\n";
	else
		cout << "Не съдържа цифрата 5\n";

}

int prime() {
	int n;
	cout << "n = ";cin >> n;
	int d = 1;
	do
	  d++;
	while (d < n && n % d != 0);
	// d == n || n % d == 0
	// ДА, няма делител, числото е просто:  d == n
	// НЕ, има делител, числото е съставно: d < n && n % d == 0
	cout << n;
	if (n == 1 || d < n) {
		// Знаем, че n % d == 0, понеже сме излезли от цикъла
		cout << " НЕ";
	}
	cout << " е просто\n";
	return 0;
}

int sqrtx() {
	double x, eps;
	cout << "x = ";cin >> x;
	cout << "eps = ";cin >> eps;
	double y = x, py;
	do {
		py = y; // Запомняме предната стойност на y
		y = (y + x/y)/2;
	} while (fabs(py - y) >= eps);
	// fabs(py - y) < eps
	cout << "sqrt(" << x << ") = " << y << endl;
}

int main() {
	double x, eps, sum = 0, y = 1;
	int n = 0;
	cout << "x = ";cin >> x;
	cout << "eps = ";cin >> eps;
	do {
		// имаме y_n, искаме да сметнем y_n+1
		sum += y; // Натрупваме y_n
		y *= x /= ++n; // y n+1
	} while (fabs(y) >= eps);
	cout << "exp(" << x << ") = " << sum << endl;
}
