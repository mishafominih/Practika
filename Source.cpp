#include "Maze.h"



int main() {
	Maze mase(5, 5);
	for (int i = 1; i < 4; i++) {
		mase.makeConnection(i - 1, i, i, i);
		mase.makeConnection(i, i, i, i + 1);
	}
	mase.printMaze();
}