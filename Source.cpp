#include "Maze.h"
#include "MTreeNode.h";
#include <iostream>

using namespace std;

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

int main() {
	Maze mase(5, 5);
	for (int i = 0; i < 4; i++) {
		mase.makeConnection(i, 0, i + 1, 0);
		mase.makeConnection(i, 1, i + 1, 1);
		if(i != 0)
			mase.makeConnection(i - 1, i, i, i);
		mase.makeConnection(i, i, i, i + 1);
		if(i != 3)
			mase.makeConnection(i, i + 1, i, i + 2);
		if(i < 2)
			mase.makeConnection(i, i + 2, i, i + 3);
		if(i > 1)
			mase.makeConnection(3, i, 4, i);
	}
	mase.makeConnection(0, 3, 0, 4);
	mase.makeConnection(2, 2, 3, 2);
	mase.makeConnection(3, 4, 4, 4);
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