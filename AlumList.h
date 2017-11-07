#pragma once
#include "AlumSListType.h"
#include "Alum.h"

class AlumList
{
public:
	AlumList();
	~AlumList();
	bool addAlum(Alum& alum);
	bool setScore(int index, float score);
	bool removeAlum(Alum& alum);
	void printListbyScore();
	void print();
	int getSize();

private:
	AlumSListType *head;
	AlumSListType *tail;
	Alum** heapSort();
	void heapify(Alum** arr, int n, int i);
	void heapSort(Alum** arr, int n);
	void listToArray(Alum** array);
};

