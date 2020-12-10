#include "MTreeNode.h"

MTreeNode::MTreeNode() {

}

MTreeNode::MTreeNode(MTreeNode* parent) {
	m_parent = parent;
}

bool MTreeNode::addChild(int i, int j){
	count++;
	MTreeNode* children = new MTreeNode[count];
	for (int i = 0; i < count - 1; i++)
		children[i] = m_children[i];
	delete[] m_children;
	auto child = new MTreeNode(this);
	child->m_i = i;
	child->m_j = j;
	child->m_distance = m_distance + 1;
	children[count - 1] = *child;
	m_children = children;
	return true;
}

MTreeNode* MTreeNode::hasChild(int i, int j){
	if (m_i == i && m_j == j) return this;
	for (int ii = 0; ii < count; ii++) {
		if (child(ii) != nullptr) {
			auto ch = child(ii);
			ch = ch->hasChild(i, j);
			if (ch != nullptr) return ch;
		}
	}
	return nullptr;
}

MTreeNode* MTreeNode::child(int i) const {
	if (m_children == nullptr) return nullptr;
	if (i >= count) return nullptr;
	return &m_children[i];
}

MTreeNode* MTreeNode::beginTree(int i, int j) {
	auto tree = new MTreeNode(nullptr);
	tree->m_i = i;
	tree->m_j = j;
	return tree;
}
