/*
 * cond.cpp
 *
 *  Created on: 26.10.2016 г.
 *      Author: trifon
 */


#include <iostream>
using namespace std;

int increasing() {
  int a, b, c;
  cout << "a = ";cin >> a;
  cout << "b = ";cin >> b;
  cout << "c = ";cin >> c;
  cout << "Числата " << a << ',' << b << " и " << c;
  /*
  if (a < b && b < c) ;
  else {*/
  // if (!(a < b && b < c)) {
  if (a >= b || b >= c) {
 	  cout << " НЕ";
  }
  cout << " образуват растяща редица\n";
}

int findmin() {
  int a, b, c;
  cout << "a = ";cin >> a;
  cout << "b = ";cin >> b;
  cout << "c = ";cin >> c;
  int min = a;
  // нищо не знаем
  // min <= a
  if (b < min)
	  min = b;
  // min <= a && min <= b
  if (c < min)
	  min = c;
  // min <= a && min <= b && min <= c
  cout << "min(" << a << ',' << b << ',' << c << ") = "
		  << min << endl;
}

int main() {
  int a, b, c;
  cout << "a = ";cin >> a;
  cout << "b = ";cin >> b;
  cout << "c = ";cin >> c;
  // 1. намираме кое е най-малкото, после най-голямото и другото е "средното"
  // 2. сравняваме всяко със всяко
}
