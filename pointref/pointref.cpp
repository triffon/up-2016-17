/*
 * pointref.cpp
 *
 *  Created on: 7.12.2016 г.
 *      Author: trifon
 */



#include <iostream>
using namespace std;

 void print(char const* p) {
    while (*p) {
        // !!! if (*p == 'l') *p = 'X';
        cout << *p++;
    }
}

int testPointers() {
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
    print("Goodbye, world!");
    // !!! char* ps = "Hi C++!";
    // !!! ps[1] = 'o';
	return 0;
}

int main() {
    int a[10], *p = &a[2],
               *pa[2] = { a + 3, &a[6] },
               **q = &pa[1];
    // !!! *p = &[2];
//     p = a[2];
    p = &a[2];
    p = a + 2;
    // p = *(a + 2); <-> p = a[2];
    // !!!*p = &a[2];
    // !!! *p = a[2];
    pa[0] = &a[3];
    pa[1] = pa[0] + 3;
    // !!! *pa[0] = &a[3];
    q = pa + 1;
    // **q = ....
    *(p + 2) = 8;
    // !!! p + 2 = 8;
    // !!! &(p + 2) = 8;
    p[2] = 8;
    // !!! **(q-2) = 8;
    // !!! **(q-1+1) = 8; <-> **q = 8;
    *(*q-2) = 8; // <-> pa[1]
    *(*(q-1)+1) = 8;
    *(*(q+0)-2) = 8; // <-> pa[1]
    q[0][-2] = 8;
    q[-1][1] = 8;



    void* r = p;
    int* s = (int*)r;
    // !!! s = (int*)(int)1.5424243;
    return 0;
}


