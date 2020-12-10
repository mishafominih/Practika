#include <iostream>
#include <vector>
#include "SLList.h"
#include <time.h>

using namespace std;

void printData(SLList* e)
{
	cout << e->getData() << endl;
}

void printSLList(const SLList* list) {
	cout << "SLList:" << endl;
	auto e = new SLList(*list);
	printData(e);
	while (e->hasNext())
	{
		e = e->next();
		printData(e);
	}
}

bool find(SLList* e, int val) {
	auto elem = e;
	if (elem->getData() == val) return true;
	while (elem->hasNext()) {
		elem = elem->next();
		if (elem->getData() == val) return true;
	}
	return false;
}

SLList* deleteEqual(SLList* e) {
	auto first = SLList::beginList(e->getData());
	auto now = first;
	while (e->hasNext()) {
		e = e->next();
		if (find(first, e->getData())) continue;
		now = now->addElement(e->getData());
	}
	return first;
}

SLList* findElementEnd(SLList* e, int count) {
	auto res = e;
	auto end = e;
	for (int i = 0; i < count - 1; i++)
		end = end->next();
	while (end->hasNext())
	{
		end = end->next();
		res = res->next();
	}
	return res;
}

int getRandSix()
{
	return rand() % 6;
}

int main() {
	srand(time(NULL));
	setlocale(0, "");
	auto first = SLList::beginList(getRandSix());
	auto elem = first;
	for (int i = 0; i < 9; i++) {
		elem = elem->addElement(getRandSix());
	}
	printSLList(first);
	cout << "без повторений:" << endl;
	printSLList(deleteEqual(first));
	cout << "5 элемент с конца: " << findElementEnd(first, 5)->getData();
}

