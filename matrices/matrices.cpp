/*
 * matrices.cpp
 *
 *  Created on: 23.11.2016 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

const int MAX = 100;

int main() {
	int a[MAX][MAX];
	int m, n;
	cout << "m = "; cin >> m;
	cout << "n = "; cin >> n;
	for(int i = 0; i < m; i++)
		// За всеки ред
		for(int j = 0; j < n; j++) {
			// За всеки елемент в реда i
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			cout << a[i][j] << '\t';
		cout << endl;
	}

	int sums[MAX] = { 0 };

	for(int i = 0; i < m; i++)
		// За всяка колона
		for(int j = 0; j < n; j++)
			// минаваме през всеки от елементите ѝ
			sums[j] += a[i][j];

	cout << endl;
	for(int j = 0; j < n; j++)
		cout << sums[j] << '\t';
	cout << endl;

	int x;
	cout << "x = ";cin >> x;

	for(int i = 0; i < m; i++) {
		int j = 0;
		while (j < n && a[i][j] != x)
			j++;
		if (j < n)
			cout << "Среща се в ред " << i << endl;
	}

	int j = 0, min = 1;
	while (j < n && min % 2 != 0) {
		min = a[0][j];
		for(int i = 1; i < m; i++)
			if (a[i][j] < min)
				min = a[i][j];
		j++;
	}
	// ДА: min % 2 == 0
	// НЕ: j == n && min % 2 != 0
	if (min % 2 == 0)
		cout << "Има такава колона, тя е с номер " << j-1 << endl;
	else
		cout << "Няма такава колона\n";

	for(int i = 0; i < m; i++) {
		for(int j = 0; j <= i; j++)
			cout << a[i-j][j] << ' '; // x + j == i
		cout << endl;
	}

	for(int i = 0; i < max(m, n); i++)
		for(int j = i + 1; j < max(m, n); j++) {
			int tmp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = tmp;
		}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			cout << a[i][j] << '\t';
		cout << endl;
	}



}


