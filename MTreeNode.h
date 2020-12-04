#pragma once
class MTreeNode
{
public:
	int i() const { return m_i; }
	int j() const { return m_j; }
	const MTreeNode* parent() const { return m_parent; }
	MTreeNode* child(int i) const;
	int distance() const { return m_distance; }
	int childCount() const { return count; }
	bool addChild(int i, int j);
	MTreeNode* hasChild(int i, int j);
	static MTreeNode* beginTree(int i, int j);
private:
	MTreeNode();
	MTreeNode(MTreeNode* parent);
	int m_i = 0, m_j = 0;
	MTreeNode* m_parent;
	MTreeNode* m_children;
	int m_distance = 0;
	int count = 0;
};

