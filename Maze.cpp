#include "Maze.h"
#include <algorithm>
#include <iostream>

using namespace std;

Maze::Maze(int n, int m) {
	m_field = new MCell[n * m];
	this->n = n;
	this->m = m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			m_field[i * n + j] = MCell();
		}
	}
}

const MCell& Maze::cell(int i, int j) const {
	return m_field[i * n + j];
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2) {
	auto min_i = min(i1, i2);
	auto min_j = min(j1, j2);
	auto max_i = max(i1, i2);
	auto max_j = max(j1, j2);
	auto cell = m_field[min_i * n + min_j];
	int d = max_i - min_i + max_j - min_j;
	if (d == 0) 
		return true;
	if (d == 1) {
		if (max_i == min_i)return cell.right();
		return cell.down();
	}
	return min_j == max_j ? hasConnection(min_i + 1, min_j, max_i, max_j) : false ||
		min_i == max_i ? hasConnection(min_i, min_j + 1, max_i, max_j) : false;
}


bool Maze::makeConnection(int i1, int j1, int i2, int j2) {
	auto i = std::min(i1, i2);
	auto j = std::min(j1, j2);
	if (i1 == i2)
		m_field[i * n + j].m_right = true;
	else
		m_field[i * n + j].m_down = true;
	return true;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2) {

	auto i = std::min(i1, i2);
	auto j = std::min(j1, j2);
	if (i1 == i2)
		m_field[i * n + j].m_right = false;
	else
		m_field[i * n + j].m_down = false;
	return false;
}

void Maze::printMaze() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool left = false;
			bool up = false;
			if (i != 0)
				up = m_field[(i - 1) * n + j].down();
			if (j != 0)
				left = m_field[i * n + j - 1].right();
			auto right = m_field[i * n + j].right();
			auto down = m_field[i * n + j].down();
			char simvol;
			if (left && up && right && down)
				simvol = 197;
			else if (left && up && right)
				simvol = 193;
			else if (left && up && down)
				simvol = 180;
			else if (left && down && right)
				simvol = 194;
			else if (up && down && right)
				simvol = 195;
			else if (left && up)
				simvol = 217;
			else if (up && right)
				simvol = 192;
			else if (left && down)
				simvol = 191;
			else if (down && right)
				simvol = 218;
			else if (down && up)
				simvol = 179;
			else if (left && right)
				simvol = 196;
			else
				simvol = '0';
			cout << simvol;
		}
		cout << endl;
	}
}