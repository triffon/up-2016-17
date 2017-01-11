/*
 * labyrinth.cpp
 *
 *  Created on: 11.01.2017 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

const int MAX = 100;

char labyrinth[MAX][MAX] = {
		"*$** ",
		"* $  ",
		"$*** ",
		"*    ",
		"  **$"
};

const int WIDTH = 5;
const int HEIGHT = 5;

void printPoint(char const* text, int x, int y) {
	cout << text << " (" << x << ',' << y << ")\n";
}

void printLabyrinth() {
	for(int i = 0; i < HEIGHT; i++)
		cout << labyrinth[i] << endl;
}

bool findTreasure(int x, int y) {
	printPoint("Пробваме да стъпим на", x, y);
	if (x < 0 || y < 0 || x >= HEIGHT || y >= WIDTH || labyrinth[x][y] == '*') {
		printPoint("Не можем да стъпим на", x, y);
		return false;
	}
	if (labyrinth[x][y] == '"') {
		printPoint("Вече сме били на", x, y);
		return false;
	}
	if (labyrinth[x][y] == '$') {
		printPoint("Намерихме съкровището на", x, y);
		return true;
	}
	// 0 <= x < HEIGHT && 0 <= y < WIDTH && labyrinth[x][y] == ' '
	printPoint("Стъпваме на", x, y);
	labyrinth[x][y] = '"';
	// север
	if (findTreasure(x - 1, y    )) {
		printPoint("Пътят минава през", x - 1, y);
		return true;
	}
	// изток
	if (findTreasure(x    , y + 1)) {
		printPoint("Пътят минава през", x, y + 1);
		return true;
	}
	// юг
	if (findTreasure(x + 1, y    )) {
		printPoint("Пътят минава през", x + 1, y);
		return true;
	}
	// запад
	if (findTreasure(x    , y - 1)) {
		printPoint("Пътят минава през", x, y - 1);
		return true;
	}
	printPoint("Стъпваме назад от", x, y);
	labyrinth[x][y] = 'X';
	return false;
}

int findAllTreasures(int x, int y) {
	printPoint("Пробваме да стъпим на", x, y);
	if (x < 0 || y < 0 || x >= HEIGHT || y >= WIDTH || labyrinth[x][y] == '*') {
		printPoint("Не можем да стъпим на", x, y);
		return 0;
	}
	if (labyrinth[x][y] == '"') {
		printPoint("Вече сме били на", x, y);
		return 0;
	}
	int foundTreasures = 0;
	if (labyrinth[x][y] == '$') {
		printPoint("Намерихме съкровище на", x, y);
		foundTreasures = 1;
	}
	// 0 <= x < HEIGHT && 0 <= y < WIDTH && labyrinth[x][y] == ' '
	printPoint("Стъпваме на", x, y);
	labyrinth[x][y] = '"';
	// север
	foundTreasures += findAllTreasures(x - 1, y    );
	// изток
	foundTreasures += findAllTreasures(x    , y + 1);
	// юг
	foundTreasures += findAllTreasures(x + 1, y    );
	// запад
	foundTreasures += findAllTreasures(x    , y - 1);
	printPoint("Стъпваме назад от", x, y);
	labyrinth[x][y] = 'X';
	return foundTreasures;
}

int main() {
	//cout << findTreasure(4, 1) << endl;
	cout << findAllTreasures(4, 1) << " намерени съкровища\n";
	printLabyrinth();
	return 0;
}


