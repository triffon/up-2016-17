/*
 * arrays.cpp
 *
 *  Created on: 16.11.2016 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

const int MAX = 10;

int a[MAX];

int readArray() {
	int n;
	do {
	 cout << "n = "; cin >> n;
	} while (n <= 0 || n > MAX); // n in [1;MAX]
	for(int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";cin >> a[i];
	}
	return n;
}

void printArray(int n) {
	for(int i = 0; i < n; i++)
		cout << "a[" << i << "] = " << a[i] << endl;
	cout << endl;
}

int sumArray(int n) {
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += a[i];
	return sum;
}

bool inArray(int x, int start, int n) {
	/*
	for(int i = 0; i < n; i++)
		if (a[i] == x)
			return true;
	return false;
	*/
	int i = start;
	while (i < n && a[i] != x)
		i++;
	// ДА: i < n && a[i] == x
	// НЕ: i == n
	return i < n;
	// !!!! return a[i] == x;
}

bool isSorted(int n) {
	int i = 0;
	while (i < n - 1 && a[i] <= a[i+1])
		i++;
	// ДА: i == n - 1
	// НЕ: a[i] > a[i+1]
	return i == n - 1;
}

bool different(int n) {
	/*
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if (a[i] == a[j])
				return false;
	return true;
	*/
	/*
	int i = 0, j = n;
	while (i < n && j == n) {
		j = i + 1;
		// Търсим дали a[i] се среща в масива от i+1,...,n-1
		while (j < n && a[i] != a[j])
			j++;
		// ДА: j == n
		// НЕ: j < n && a[i] == a[j]
		i++;
	}*/
	int i = 0;
	while (i < n && !inArray(a[i], i + 1, n))
		i++;
	// ДА: i == n
	// НЕ: j < n
	return i == n;
}

void selectionSort(int n) {
	for(int i = 0; i < n - 1; i++) { // n - 1 стъпки
		// чертата е преди елемента a[i]
		// т.е. елементите от a[0] до a[i-1] са си на местата
		// а останалите може да са разбъркани
		// искаме да намерим най-малкия елемент от a[i] до a[n-1]
		int minIndex = i;
		for(int j = i + 1; j < n; j++)
			// a[minIndex] е най-малкия елемент от a[i] до a[j-1]
			// Нека да го осигурим за a[j]
			if (a[j] < a[minIndex])
				minIndex = j;
		// a[minIndex] е най-малкия елемент от a[i] до a[j]

		// j == n
		// a[minIndex] е най-малкия елемент от a[i] до a[n-1]
		// Да го сложим на мястото му!
		// т.е. на позиция i
		// т.е. да разменим a[i] с a[minIndex]
		int tmp = a[i];
		a[i] = a[minIndex];
		a[minIndex] = tmp;

		// елементите от a[0] до a[i] са си на местата
	}
	// i == n - 1
	// елементите от a[0] до a[n-2] са си на местата
	// Но това гарантира, че A[n-1] също си е на мястото
}

int testArrays() {
	int n = readArray();
	printArray(n);
	cout << "Сумата на числата е " << sumArray(n) << endl;
	int x;
	cout << "x = ";cin >> x;
	cout << "Числото " << x;
	if (!inArray(x, 0, n))
		cout << " НЕ";
	cout << " се среща в масива\n";
	cout << "Елементите на масива";
	if (!isSorted(n))
		cout << " НЕ";
	cout << " образуват монотонно растяща редица\n";

	if (different(n))
		cout << "Всички числа в масива са различни\n";
	else
		cout << "В масива има поне две еднакви числа\n";
	selectionSort(n);
	printArray(n);
	return 0;
}

int main() {
	int n, m;
	int a[MAX], b[MAX], c[2 * MAX];

	do {
	 cout << "n = "; cin >> n;
	} while (n <= 0 || n > MAX); // n in [1;MAX]
	for(int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";cin >> a[i];
	}

	do {
	 cout << "m = "; cin >> m;
	} while (m <= 0 || m > MAX); // m in [1;MAX]
	for(int i = 0; i < m; i++) {
		cout << "b[" << i << "] = ";cin >> b[i];
	}

	int i = 0, j = 0, k = 0;
	while (i < n && j < m)
		if (a[i] < b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	// i == n || j == m
	// Точно единият масив е "свършил"
	// Трябва да прехвърлим другия в C

	// В a има още елементи
	// да ги прехвърлим в c
	while (i < n)
		c[k++] = a[i++];

	while (j < m)
		c[k++] = b[j++];

	// i == n && j == m && k == m + n
	for(int i = 0; i < k; i++)
		cout << "c[" << i << "] = " << c[i] << endl;

	return 0;
}
