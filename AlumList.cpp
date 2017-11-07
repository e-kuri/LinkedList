#pragma once
#include "stdafx.h"
#include "AlumList.h"
#include <iostream>


AlumList::AlumList()
{
	this->head = NULL;
	this->tail = NULL;
}


AlumList::~AlumList()
{
	/*
	AlumSListType *current = head;
	while (current != NULL) {
		current = current->getNext();
		if (current != NULL)
		{
			delete(current->getPrev());
		}
		delete(this->tail);
	}
	*/
}

bool AlumList::addAlum(Alum& alum)
{
	if (this->tail == NULL)
	{
		AlumSListType *toAdd = new AlumSListType(NULL, NULL, &alum);
		this->head = toAdd;
		this->tail = toAdd;
	}
	else
	{
		AlumSListType *toAdd = new AlumSListType(NULL, tail, &alum);
		tail->setNext(toAdd);
		this->tail = toAdd;
	}
	return true;
}

bool AlumList::removeAlum(Alum& alum) {
	AlumSListType *current = head;
	while (current != NULL) {
		if (&(current->getAlum()) == &alum) {
			AlumSListType *currPrev = current->getPrev();
			AlumSListType *currNext = current->getNext();
			if (currPrev != NULL)
			{
				currPrev->setNext(currNext);
			}
			else
			{
				this->head = currNext;
			}
			if (currNext != NULL)
			{
				currNext->setPrev(currPrev);
			}
			else
			{
				this->tail = currPrev;
			}
			return true;
		}
		current = current->getNext();
	}
	return false;
}

bool AlumList::setScore(int index, float score)
{
	AlumSListType *current = head;
	int i = 0;
	while (current != NULL) {
		if (i == index)
		{
			current->getAlum().setScore(score);
			return true;
		}
		current = current->getNext();
		i++;
	}
	return false;
}


void AlumList::printListbyScore() 
{
	Alum** sortedAlums = heapSort();
	for (int i = 0; i < getSize(); i++) {
		sortedAlums[i]->print();
		std::cout << "\n";
	}
	free(sortedAlums);
}

void AlumList::print() 
{
	AlumSListType *current = head;
	while (current != NULL) {
		current->getAlum().print();
		std::cout << "\n";
		current = current->getNext();
	}
}



int AlumList::getSize()
{
	AlumSListType *current = head;
	int i = 0;
	while (current != NULL) {
		i++;
		current = current->getNext();
	}
	return i;
}

Alum** AlumList::heapSort() {
	int size = getSize();
	Alum** sortedAlums = (Alum**)malloc(sizeof(Alum*) * size);
	listToArray(sortedAlums);
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapify(sortedAlums, size, i);
	}

	for (int i = size - 1; i >= 0; i--)
	{
		std::swap(sortedAlums[0], sortedAlums[i]);
		heapify(sortedAlums, i, 0);
	}
	return sortedAlums;
}

void AlumList::listToArray(Alum** array)
{
	AlumSListType *current = head;
	int i = 0;
	while(current != NULL) {
		array[i++] = &current->getAlum();
		current = current->getNext();
	}
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void AlumList::heapify(Alum** arr, int n, int i)
{
	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2;  // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l]->getScore() > arr[largest]->getScore())
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r]->getScore() > arr[largest]->getScore())
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		std::swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void AlumList::heapSort(Alum** arr, int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end
		std::swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}