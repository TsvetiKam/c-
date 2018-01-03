#include "stdafx.h"
#include <iostream>

using namespace std;

int const Width = 10;
int const Height = 10;
int treasureCount = 0;

char labyrinth[100][100] = {
	" **$ * **$",
	"  * ** *$*",
	" *$ ****  ",
	"  *  *$   ",
	"*        *",
	"* * **** $",
	"**$  $ ** ",
	"  $*** *$ ",
	"$***   ** ",
	"  $*$* *  "
};

void findTreasure(int x, int y) {
	
	// Invalid step
	if(x < 0 || x >= Height || y < 0 || y >= Width || labyrinth[x][y] == '*'){
		return;
	}
	//Checked step
	if (labyrinth[x][y] == '"') {
		return;
	}
	//Find treasure
	if (labyrinth[x][y] == '$') {
		cout << "You have found treasure on (" << x << ',' << y << ')' << endl;
		treasureCount++;
	}
	labyrinth[x][y] = '"';

	findTreasure(x - 1, y);

	findTreasure(x, y + 1);

	findTreasure(x + 1, y);
	
	findTreasure(x, y - 1);
}


int main()
{
	
	findTreasure(4,3);
	cout << "Treasures found:" << treasureCount << endl;
    return 0;
}

