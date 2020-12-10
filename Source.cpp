#include "Maze.h"
#include <iostream>

using namespace std;

int main() {
	Maze mase(5, 5);
	for (int i = 1; i < 4; i++) {
		mase.makeConnection(i - 1, i, i, i);
		mase.makeConnection(i, i, i, i + 1);
	}
	mase.makeConnection(0, 0, 0, 1);
	mase.makeConnection(3, 4, 4, 4);
	mase.printMaze();
}