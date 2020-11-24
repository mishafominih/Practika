#pragma once
class Maze;

class MCell
{
private:
	MCell();
	bool m_down = false;
	bool m_right = false;
public:
	bool right();
	bool down();
	friend class Maze;
};

