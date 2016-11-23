/*
 * strings.cpp
 *
 *  Created on: 23.11.2016 г.
 *      Author: trifon
 */

#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100;

int testStings() {
	char q[6] = "Hello";
	char s[MAX] = "Test"; // { '\0' };
	char p[MAX] = "Hello";
	cout << "s = ";
	// !!! cin >> s;
	cin.getline(s, MAX);
	cout << s << ' ' << (void*)s << endl;
	cout << p << ' ' << (void*)p << endl;
	cout << q << ' ' << (void*)q << endl;
	cout << strlen(s) << endl;
	char s2[MAX];
	strcpy(s2, s); // "s2 = s"
	cout << s2 << endl;
	cout << strcmp(s, s2) << endl;
	cout << strcmp(s, p) << endl;
	cout << (char)strcmp(s, p) << endl;
	if (strcmp(s, p) > 0) cout << s << " е след " << p << endl;
	strcat(s, " Goodbye, world!");
	cout << s << ' ' << s2 << endl;
	char c;
	cout << "c = ";cin >> c;
	if (strchr(s, c))
		cout << "Среща се: " << strchr(s, c) << endl;
	else
		cout << "Не се среща!\n";
	if (strstr(s, "or"))
		cout << "Среща се: " << strstr(s, "or") << endl;
	else
		cout << "Не се среща!\n";

	return 0;
}


int palindrome() {
	char s[MAX] = "";
	cin.getline(s, MAX);
	int n = strlen(s), mid = n / 2 - 1;
	int i = 0;
	while (i <= mid && s[i] == s[n-1-i])
		i++;
	// НЕ: s[i] != s[n-1-i]
	// ДА: i > mid
	cout << "Низът \"" << s << '"';
	if (i <= mid)
		cout << " НЕ";
	cout << " е палиндром.\n";
}

bool isLetter(char c) {
	return 'A' <= c && c <= 'Z' || 'a' <= c && c <= 'z';
}

int main() {
	char s[MAX] = "";
	cin.getline(s, MAX);

	int i = 0, count = 0;
	bool inWord = false;
	while (s[i] != '\0') {
		// if (inWord != isLetter(s[i]))
		//	inWord = !inWord;

		if (inWord && !isLetter(s[i]))
			inWord = false;
		else if (!inWord && isLetter(s[i])) {
			inWord = true;
			count++;
		}
		i++;
	}
	// s[i] == '\0'
	cout << "Имаме " << count << " думи\n";
}
