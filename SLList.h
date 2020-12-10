#pragma once
class SLList
{
private:
	SLList* m_nextElem;
	int m_data;
	SLList(int data);
public:
	int getData();
	void setData(int data);
	SLList* next();
	bool hasNext();
	static SLList* beginList(int data);
	SLList* addElement(int data);
	void removeNext();
};

