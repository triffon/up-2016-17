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
  // нищо не знаем
  int min = a;
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

int sort3() {
  int a, b, c;
  cout << "a = ";cin >> a;
  cout << "b = ";cin >> b;
  cout << "c = ";cin >> c;
  // 1. намираме кое е най-малкото, после най-голямото и другото е "средното"

  /*
  // нищо не знаем
  int min = a;
  // min <= a
  if (b < min)
	  min = b;
  // min <= a && min <= b
  if (c < min)
	  min = c;
  // min <= a && min <= b && min <= c

  // нищо не знаем
  int max = a;
  // max >= a
  if (b > max)
	  max = b;
  // max >= a && max >= b
  if (c > max)
	  max = c;
  // max >= a && max >= b && max >= c
  // кое е средното????

*/

  // 2. сравняваме всяко със всяко
/*
  // по-добре с блокове!
  if (a < b)
	  // a < b
	  if (b < c)
		  // a < b && b < c
		  cout << a << ',' << b << ',' << c << endl;
	  else
		  // a < b && b >= c
		  if (a < c)
			  // a < c <= b
			  cout << a << ',' << c << ',' << b << endl;
		  else
			  // a >= c && a < b && b >= c
			  // c <= a < b
			  cout << c << ',' << a << ',' << b << endl;
  else
	  // b <= a
	  if (a < c)
		  // b <= a < c
		  cout << b << ',' << a << ',' << c << endl;
	  else
		  // c <= a && b <= a
		  if (b < c)
			  // b < c <= a
			  cout << b << ',' << c << ',' << a << endl;
		  else
			  // c <= b <= a
			  cout << c << ',' << b << ',' << a << endl;
*/
  // 3. Разменяме така, че да получим a <= b <= c
  if (a > b) {
	  // Разменяме a и b
	  int x = a;
	  a = b;
	  b = x;
  }
  // a <= b
  if (b > c) {
	  // Разменяме b и c
	  int x = b;
	  b = c;
	  c = x;
  }
  // b <= c && (a <= b || a <= c)
  // Изкарахме най-голямото число да е в c
  // сега трябва да видим кое е "средното"
  if (a > b) {
	  // Разменяме a и b
	  int x = a;
	  a = b;
	  b = x;
  }
  // a <= b <= c
  cout << a << ',' << b << ',' << c << endl;
}

int swichtest() {
	int x;
	cout << "x = ";cin >> x;
	switch (x) {
	case 1 : x++; break;
	case 2 : x += 2; break;
	default: x += 5;
	}
	cout << "x = " << x << endl;
}

int calculator() {
	int a, b;
	char op;
	cin >> a >> op >> b;
	cout << " = ";
	switch (op) {
	case '+': cout << a + b << endl;break;
	case '-': cout << a - b << endl;break;
	case '*': cout << a * b << endl;break;
	case '/': cout << a / b << endl;break;
	case '%': cout << a % b << endl;break;
	default : cerr << "Непозната операция!" << endl;
	}
}

int main() {
	char letter;
	cin >> letter;
	if (letter < 'a' || letter > 'z') {
		cerr << "Не е въведена малка латинска буква!\n";
		return 0;
	}
	switch (letter) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u': cout << "Гласна буква\n";break;
	default : cout << "Съгласна буква\n";break;
	}
}
