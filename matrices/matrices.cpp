/*
 * matrices.cpp
 *
 *  Created on: 23.11.2016 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

const int MAX = 100;

int matrices() {
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


void print3(int mat[5][5])
{
    const int size = 5;
    // отпечатваме всички "диагоналчета" на две групи
    for (int d = 0; d < size; d++)
        for (int i = 0; i <= d; i++)
            cout << mat[d - i][i] << " ";

    for (int d = 4; d > 0; d--)
        for (int i = 0; i < d; i++)
            cout << mat[size - 1 - i][size - d + i] << " ";
    cout << endl;
}

void print4(int mat[5][5])
{
    const int size = 5;
    // аналогично на предишната, просто отрязваме диагоналите по-рано
    for (int d = 0; d < size; d++)
        for (int i = 0; i <= d/2; i++)
            cout << mat[d - i][i] << " ";

    for (int d = 4; d > 0; d--)
        for (int i = 0; i < (d + 1)/2; i++)
            cout << mat[size - 1 - i][size - d + i] << " ";
    cout << endl;
}

void print5(int mat[5][5])
{
    const int size = 5;
    // всяка начупена линия, която отпечатваме, е от две последователни части
    for (int line = 0; line < size; line++)
    {
        // първо хоризонталната...
        for (int i = 0; i < line + 1; i++)
            cout << mat[line][i] << " ";
        // ...после вертикалната
        for (int i = 0; i < line; i++)
            cout << mat[line - 1 - i][line] << " ";
    }
    cout << endl;
}

void print6(int mat[5][5])
{
    const int size = 5, mid = size / 2;
    cout << mat[mid][mid] << " ";
    // тук всяка начупена линия ще наричаме "обиколка"
    // и тя е съставена от 4 прости части
    for (int lap = 1; lap <= mid; lap++)
    {
        for (int i = 0; i < 2 * lap; i++)
            cout << mat[mid - lap][mid + 1 - lap + i] << " ";
        for (int i = 0; i < 2 * lap; i++)
            cout << mat[mid + 1 - lap + i][mid + lap] << " ";
        // наблюдение - третата и четвъртата "част" са симетрични на първите две спрямо mid
        for (int i = 0; i < 2 * lap; i++)
            cout << mat[mid + lap][mid - (1 - lap + i)] << " ";
        for (int i = 0; i < 2 * lap; i++)
            cout << mat[mid - (1 - lap + i)][mid - lap] << " ";
    }
    cout << endl;
}

int main()
{
    int mat3[5][5] = { {1,3,6,10,15},{2,5,9,14,19},{4,8,13,18,22},{7,12,17,21,24},{11,16,20,23,25} };
    int mat4[5][5] = { {1,0,0,0,0},{2,4,0,0,0},{3,6,9,0,0},{5,8,11,13,0},{7,10,12,14,15} };
    int mat5[5][5] = { {1,4,9,16,25},{2,3,8,15,24},{5,6,7,14,23},{10,11,12,13,22},{17,18,19,20,21} };
    int mat6[5][5] = { {25,10,11,12,13},{24,9,2,3,14},{23,8,1,4,15},{22,7,6,5,16},{21,20,19,18,17} };

    print3(mat3); // очакваме числата 1-25
    print4(mat4); // очакваме числата 1-15
    print5(mat5); // очакваме числата 1-25
    print6(mat6); // очакваме числата 1-25
}
