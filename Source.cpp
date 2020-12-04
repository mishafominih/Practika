#include "Maze.h"
#include "MTreeNode.h";
#include <iostream>
#include "Source.h"

using namespace std;

int main() {
	Maze mase(5, 5);
	for (int i = 1; i < 4; i++) {
		mase.makeConnection(i - 1, i, i, i);
		mase.makeConnection(i, i, i, i + 1);
	}
	mase.makeConnection(0, 0, 1, 0);
	mase.makeConnection(0, 0, 0, 1);
	mase.makeConnection(1, 1, 2, 1);
	mase.makeConnection(0, 1, 0, 2);
	mase.makeConnection(0, 2, 0, 3);
	mase.makeConnection(2, 3, 2, 4);
	mase.makeConnection(0, 3, 0, 4);
	mase.makeConnection(1, 2, 1, 3);
	mase.makeConnection(1, 3, 1, 4);
	mase.makeConnection(1, 0, 2, 0);
	mase.makeConnection(2, 0, 3, 0);
	mase.makeConnection(2, 1, 3, 1);
	mase.makeConnection(2, 2, 3, 2);
	mase.makeConnection(3, 1, 4, 1);
	mase.makeConnection(3, 2, 4, 2);
	mase.makeConnection(3, 0, 4, 0);
	mase.makeConnection(3, 4, 4, 4);
	mase.makeConnection(3, 3, 4, 3);
	mase.printMaze();

	auto e = MTreeNode::beginTree(0, 0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i != 0 || j != 0) {
				if (i != 0 && mase.hasConnection(i - 1, j, i, j))
					e->hasChild(i - 1, j)->addChild(i, j);
				else if (j != 0 && mase.hasConnection(i, j - 1, i, j))
					e->hasChild(i, j - 1)->addChild(i, j);
			}
		}
	}
	cout << endl;

	print(e);
}

void print(MTreeNode* e)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			auto child = e->hasChild(i, j);
			if (child != nullptr)
				cout << child->distance();
			else
				cout << 0;
		}
		cout << endl;
	}
}
