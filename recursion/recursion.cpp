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

int gcd(int a, int b) {
	if (a == b)
		return a;
	if (a > b)
		return gcd(a - b, b);
	return gcd(a, b - a);
}

double power(double x, int n) {
	if (n == 0)
		return 1;
	if (n < 0)
		return 1 / power(x, -n);
	return x * power(x, n - 1);
}

int const MAX = 100;

long F[MAX] = { 0 };

/*
long fib(long n) {
	if (n <= 1)
		return n;
	return fib(n - 1) + fib(n - 2);
}
*/

long fib(long n) {
	if (n <= 1)
		return (F[n] = n);
	if (F[n] != 0)
		// Вече сме го смятали! Да го върнем директно
		return F[n];
	return (F[n] = fib(n - 1) + fib(n - 2));
}

// T f(U& ) {}
// U f(T& ) {}
// T = long
// U = char const*
// char const* expr(long& ) { ... }
// long        expr(char const *& ) { ... }

/*
 * <израз> ::= <цифра> | (<израз><операция><израз>)
 * expr Връща стойността на <израз> И премества s след края на
 * <израз>
 */
long expr(char const*& s) {
	if (*s >= '0' && *s <= '9')
		// премествайки s, пресмятаме стойността на цифрата
		return *s++ - '0';

	long a = expr(++s); // прескачайки '(' пресмятаме първия израз
	char op = *s; // запомняме операцията
	long b = expr(++s); // прескачайки операцията пресмятаме
						// втория израз
	s++;			    // прескачаме ')' и осигуряваме, че сочим
						// след края на израза
	switch (op) {
	case '+' : return a + b;
	case '-' : return a - b;
	case '*' : return a * b;
	case '/' : if (b == 0) return 0; else return a / b;
	default  : return 0;
	}
}

int testrec() {
	cout << fact(7) << endl;
	cout << gcd(12, 20) << endl;
	cout << power(2, -4) << endl;
	cout << fib(8) << endl;
	int n = 0;
	while (true)
		cout << fib(n++) << endl;
	return 0;
}

int testexpr() {
	char s[MAX] = "";
	cout << "Въведете израз: ";
	cin.getline(s, MAX);
	char const *p = s;
	cout << "Резултат: " << expr(p) << endl;
	return 0;
}

void readArray(long a[], int n) {
	if (n == 0)
		return;
	cout << "Моля, въведете елемент: ";
	cin >> a[0];
	readArray(a + 1, n - 1);
}

void printArray(long a[], int n) {
	if (n == 0)
		return;
	cout << a[0] << ' ';
	printArray(a + 1, n - 1);
}

long sum(long a[], int n) {
	if (n == 0)
		return 0;
	return a[0] + sum(a + 1, n - 1);
}

/*
bool found(long a[], int n, long x) {
	if (n == 0)
		return false;
	if (a[0] == x)
		return true;
	// a[0] != x
	return found(a + 1, n - 1, x);
}
*/

bool found(long a[], int n, long x) {
	return n > 0 && (a[0] == x || found(a + 1, n - 1, x));
}

bool incr(long a[], int n) {
/*	if (n <= 1)
		return true;*/
	return n <= 1 || (a[0] < a[1] && incr(a + 1, n - 1));
}

bool diff(long a[], int n) {
	return n == 0 ||
			(!found(a + 1, n - 1, a[0]) && diff(a + 1, n - 1));
}

// Връща индекса на последния елемент a[i] < x
int split(long a[], int n, long x) {
	int i = 0, j = n - 1;
	while (i != j)
		if (a[i] < x)
			// i-тия елемент си е на мястото
			// Продължаваме нататък
			i++;
		else
			if (a[j] >= x)
				// j-тия елемент си е на мястото
				// продължаваме нататък
				j--;
			else
				// трябва да разменим a[i] с a[j]
				swap(a[i], a[j]);
	// Вече i == j
	// Трябва да проверим дали a[i] е в лявата или в дясната част
	if (a[i] < x)
		// a[i] е в лявата част
		return i;
	// a[i] е в дясната част
	return i - 1;
}

void quickSort(long a[], int n) {
	if (n <= 1)
		return;
	// 1. Избираме ос
	long x = a[0];
	// 2. Разделяме масива на две части относно оста
	// Split връща индекса на последния елемент в частта <x
	int k = split(a + 1, n - 1, x) + 1;
	// 3. Поставяме оста "между" двете части на масива
	// т.е. разменим a[0] с a[k]
	swap(a[0], a[k]);
	// Сортираме лявата част, т.е. елементите <x
	quickSort(a, k);
	// Сортираме дясната част без оста, т.е. елементите >=x
	quickSort(a + k + 1, n - k - 1);
}

int main() {
	long a[MAX] = { 0 };
	int n;
	cout << "n = "; cin >> n;
	readArray(a, n);
	cout << "Сумата е: " << sum(a, n) << endl;
	cout << "Има ли 5? " << found(a, n, 5) << endl;
	cout << "Растяща? " << incr(a, n) << endl;
	cout << "Различни? " << diff(a, n) << endl;
	quickSort(a, n);
	printArray(a, n);
	return 0;
}
