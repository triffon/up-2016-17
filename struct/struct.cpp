/*
 * struct.cpp
 *
 *  Created on: 18.01.2017 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

struct Point { double x, y; };

int const MAX_NAME = 45;

struct Student {
	char name[MAX_NAME];
	int fn;
	double grade;
};

void cheater(Student s) {
	s.grade += 1;
	cout << s.grade << endl;
}

char* f() {
	char s[] = "Hello";
	return s; // !!!!
}

Student g() {
	Student s = { "Иван Колев", 61234, 5.75 };
	return s;
}

void printStudent(Student s) {
	cout << "Име   : " << s.name << endl;
	cout << "Ф№    : " << s.fn << endl;
	cout << "Оценка: " << s.grade << endl;
}

void tabulateStudent(Student s) {
	cout.width(45);
	cout << s.name;
	cout << s.fn << '\t';
	cout << s.grade << endl;
}

Student readStudent() {
	Student s;
	cout << "Въведете име: ";
	cin.getline(s.name, MAX_NAME);
	cout << "Въведете Ф№: ";
	cin >> s.fn;
	cout << "Въведете оценка: ";
	cin >> s.grade;
	cin.get();
	return s;
}

int readStudents(Student s[]) {
	int n;
	cout << "n = ";
	cin >> n;
	cin.get();
	for(int i = 0; i < n; i++)
		s[i] = readStudent();
	return n;
}

void printStudents(Student s[], int n) {
	for(int i = 0; i < n; i++) {
		cout << "Студент " << (i + 1) << endl;
		cout << "-----------------\n";
		printStudent(s[i]);
	}
}

void tabulateStudents(Student s[], int n) {
	cout.width(45);
	cout.setf(ios::left);
	cout << "Name" << "FN\t\tGrade\n";
	cout.fill('-');
	cout.width(80);
	cout << '-' << endl;
	cout.fill(' ');
	for(int i = 0; i < n; i++)
		tabulateStudent(s[i]);
}

double averageGrade(Student s[], int n) {
	double sum = 0;
	for(int i = 0; i < n; i++)
		sum += s[i].grade;
	return sum / n;
}

int test() {
	cout << sizeof(Point) << endl;
	cout << sizeof(Student) << endl;
	Student s1 = { "Иван Колев", 61234, 5.75 };
	cout << s1.name << endl;
	Student s2 = s1;
	cin.getline(s1.name, MAX_NAME);
	cout << s1.name << ' ' << s2.name << endl;
	cout << s1.grade << endl;
	cheater(s1);
	cout << s1.grade << endl;

	return 0;
}

void sortStudentsByFN(Student s[], int n) {
	for(int i = 0; i < n - 1; i++) {
		int minindex = i;
		for(int j = i + 1; j < n; j++)
			if (s[j].fn < s[minindex].fn)
				minindex = j;
		Student tmp = s[minindex];
		s[minindex] = s[i];
		s[i] = tmp;
	}
}

void sortStudentsByGrade(Student s[], int n) {
	for(int i = 0; i < n - 1; i++) {
		int minindex = i;
		for(int j = i + 1; j < n; j++)
			if (s[j].grade < s[minindex].grade)
				minindex = j;
		Student tmp = s[minindex];
		s[minindex] = s[i];
		s[i] = tmp;
	}
}

void sortStudents(Student s[], int n, bool (*lessThan)(Student,Student)) {
	for(int i = 0; i < n - 1; i++) {
		int minindex = i;
		for(int j = i + 1; j < n; j++)
			if (lessThan(s[j], s[minindex]))
				minindex = j;
		Student tmp = s[minindex];
		s[minindex] = s[i];
		s[i] = tmp;
	}
}

int main() {
	Student s[10];
	int n =  readStudents(s);
	printStudents(s, n);
	tabulateStudents(s, n);
	cout << "Average grade: " << averageGrade(s, n) << endl;
	// sortStudentsByFN(s, n);
	sortStudents(s, n, [](Student s1, Student s2) { return s1.fn < s2.fn; });
	tabulateStudents(s, n);
	// sortStudentsByGrade(s, n);
	sortStudents(s, n, [](Student s1, Student s2) { return s1.grade < s2.grade; });
	tabulateStudents(s, n);
	return 0;
}
