#include "stdafx.h"
#include <iostream>

using namespace std;

int const MAX = 100;

char labyrinth[MAX][MAX] = {
	" **$*  ",
	" ** ***",
	"     *$",
	"** *   ",
	"*  ** *",
	" $*   *",
	"** $*  "
};

int Width = 7, Height = 7;

int All$() {
	int allTreasures = 0;
	for (int i = 0; i < Width; i++)
		for (int j = 0; j < Height; j++)
			if (labyrinth[i][j] == '$')
				++allTreasures;
	return allTreasures;
}

int treasuresFound = 0;
bool way = false;

bool escapeRich(int x, int y, int treasures) {

	if (x < 0 || x > Width || y < 0 || y > Height || labyrinth[x][y] == '*') {
		return false;
	}
	if (labyrinth[x][y] == '"') {
		return false;
	}
	if (labyrinth[x][y] == '$') {
		++treasuresFound;
	}
	if (x == 6 && y == 6) {
		way = true;
	}

	labyrinth[x][y] = '"';

	escapeRich(x - 1, y, treasures);
	escapeRich(x, y + 1, treasures);
	escapeRich(x + 1, y, treasures);
	escapeRich(x, y - 1, treasures);

	if (way && treasures == treasuresFound) {
		return true;
	}
	return false;
}

int main()
{
	int treasures = 0;
	treasures = All$();
	cout << escapeRich(0, 0, treasures) << endl;
    return 0;
}

