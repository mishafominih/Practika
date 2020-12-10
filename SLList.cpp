#include "SLList.h"

int SLList::getData() {
	return m_data;
}

void SLList::setData(int data) {
	m_data = data;
}

SLList* SLList::next() {
	return m_nextElem;
}

bool SLList::hasNext() {
	return m_nextElem != nullptr;
}

SLList::SLList(int data) {
	this->m_data = data;
}

SLList* SLList::beginList(int data) {
	return new SLList(data);
}

SLList* SLList::addElement(int data) {
	if (hasNext()) return nullptr;
	auto elem = new SLList(data);
	m_nextElem = elem;
	return elem;
}

void SLList::removeNext() {
	if (!hasNext())return;
	auto next = m_nextElem;
	while (next->m_nextElem != nullptr)
	{
		auto elem = next->m_nextElem;
		delete next;
		next = elem;
	}
	delete next;
}