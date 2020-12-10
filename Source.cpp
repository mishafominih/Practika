#include "Maze.h"
#include "MTreeNode.h";
#include <iostream>
#include <time.h>

using namespace std;

void print(MTreeNode* e, int a, int b)
{
	int max = 0;
	int count = 0;
	int sum = 0;
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++) {
			auto child = e->hasChild(i, j);
			if (child != nullptr) {
				int dist = child->distance();
				if (max < dist)
					max = dist;
				count++;
				sum += dist;
			}
		}
	cout << endl;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			auto child = e->hasChild(i, j);
			if (child != nullptr) {
				if(max < 10)
					printf("%2d", child->distance());
				else
					printf("%3d", child->distance());
			}
			else
				cout << 0;
		}
		cout << endl;
	}
	cout << "max element: " << max << endl;
	cout << "midle value: " << (double)sum / count << endl;
}

MTreeNode* searchNode(const MTreeNode& tree, const int i, const int j) {
	auto parent = &tree;
	while (parent->parent() != nullptr) {
		parent = parent->parent();
	}
	return ((MTreeNode*)parent)->hasChild(i, j);
}

void buildFullMaze(Maze& iMaze, MTreeNode& tree) {
	int i = tree.i();
	int j = tree.j();
	for (int i1 = i - 1; i1 <= i + 1; i1++) {
		for (int j1 = j - 1; j1 <= j + 1; j1++) {
			if (i1 == i && j1 == j) continue;
			if (i1 == i || j1 == j) {
				if (searchNode(tree, i1, j1) == nullptr) {
					if (iMaze.makeConnection(i, j, i1, j1)) {
						tree.addChild(i1, j1);
						buildFullMaze(iMaze, *searchNode(tree, i1, j1));
					}
				}
			}
		}
	}
}

int main() {
	srand(time(NULL));
	int a, b;
	cout << "input size" << endl;
	cin >> a >> b;
	Maze mase(a, b);
	int x, y;
	x = rand() % a;
	if (x == 0 || x == a - 1)
		y = rand() % b;
	else
		y = rand() % 2 == 0 ? 0 : b - 1;
	auto e = MTreeNode::beginTree(x, y);

	buildFullMaze(mase, *e);

	mase.printMaze();
	print(e, a, b);
	return 0;
}
