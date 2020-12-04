#include "MCell.h";
#pragma once
class Maze
{
private:
	int n;
	int m;
	MCell* m_field;
public:
	Maze(int n, int m);
	const MCell& cell(int i, int j) const;
	bool hasConnection(int i1, int j1, int i2, int j2);
	bool makeConnection(int i1, int j1, int i2, int j2);
	bool removeConnection(int i1, int j1, int i2, int j2);
	void printMaze();
};

