/*
 * dynamic.cpp
 *
 *  Created on: 21.12.2016 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

double* readArray(int n) {
	/// !!!! double a[MAX];
	double *a = new double[n];
	for(int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";cin >> a[i];
	}
	return a;
}

double average(double a[], int n) {
	double s = 0;
	for(int i = 0; i < n; i++)
		s += a[i];
	return s / n;
}

double** createMatrix(int m, int n) {
	double** a = new double*[m];
	for(int i = 0; i < m; i++)
		a[i] = new double[n];
	return a;
}

void deleteMatrix(double** a, int m) {
	for(int i = 0; i < m; i++)
		delete[] a[i];
	delete[] a;
}


double** readMatrix(int m, int n) {
	double** a = createMatrix(m, n);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	return a;
}

void printMatrix(double **a, int m, int n) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			cout << a[i][j] << '\t';
		cout << endl;
	}
}

double** transposeMatrix(double** a, int m, int n) {
	double **b = createMatrix(n, m);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			b[j][i] = a[i][j];
	return b;
}


int avg() {
	int n;
	cout << "n = ";cin >> n;
	double* a = readArray(n);
	// !!! double a[n]; // !!!!!
	cout << "Средно аритметично: " << average(a, n) << endl;
	delete[] a;
	return 0;
}

int transpose() {
	int m, n;
	cout << "m = ";cin >> m;
	cout << "n = ";cin >> n;
	double** a = readMatrix(m, n);
	printMatrix(a, m, n);

	double** olda = a;
	a = transposeMatrix(a, m, n);
	deleteMatrix(olda, m);
	printMatrix(a, n, m);
	deleteMatrix(a, n);
	// !!! cout << a[1][1] << endl;
	// !!! cout << a[4][2] << endl;
	return 0;
}

int main() {
	while (true) {
		double** a = createMatrix(1000,100);
		delete[] a;
	}
}
