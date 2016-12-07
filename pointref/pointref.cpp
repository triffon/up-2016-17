/*
 * pointref.cpp
 *
 *  Created on: 7.12.2016 г.
 *      Author: trifon
 */



#include <iostream>
using namespace std;

 void print(char* p) {
    while (*p)
        cout << *p++;
}

int main() {
	double d = 1.23, *qd = &d, **qqd = &qd;
	cout << d << ' ' << qd << ' ' << qqd << endl;
	cout << *qd << ' ' << *qqd << endl;
	cout << **qqd << endl;

	int x = 5, *p = &x, *q = p, y = *p + 2;
	cout << x << ' ' << p << endl;
	// !!! cout << *p++ << endl;
	cout << (*p)++ << endl;
	cout << x << ' ' << p << ' ' << *p << endl;

	cout << sizeof(x) << ' ' << sizeof(p) << ' ' << sizeof(int******) << endl;

	int a[5] = { 1, 2, 3, 4, 5 };
	p = a + 2;
	cout << p[0] << ' ' << p[1] << ' ' << p[2] << endl;
	while (*p != 5)
        cout << *p++ << ' ';
    cout  << endl;

    for(int i = 0; i < 5; i++)
        cout << i[a] << ' ';

    char s[] = "Hello, world!";
    print(s);
    // !!! char* ps = "Hi C++!";
    // !!! ps[1] = 'o';
	return 0;
}


