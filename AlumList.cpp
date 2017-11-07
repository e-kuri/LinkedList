#include "stdafx.h"
#include "AlumList.h"


AlumList::AlumList()
{
	this->head = NULL;
	this->tail = NULL;
}


AlumList::~AlumList()
{
}

bool AlumList::addAlum(Alum& alum)
{
	if (this->tail == NULL)
	{
		AlumSListType *toAdd = new AlumSListType(NULL, NULL);
		this->head = toAdd;
		this->tail = toAdd;
	}
	else
	{
		AlumSListType *toAdd = new AlumSListType(NULL, tail);
		tail->setNext = toAdd;
		this->tail = toAdd;
	}

}

void AlumList::printListbyScore() 
{

}
int AlumList::getSize()
{
	AlumSListType *current = head;
	int i = 0;
	while (current != NULL) {
		i++;
		current = current->getNext();
	}
}

Alum* AlumList::heapSort() {
	int size = getSize();
	Alum* sortedAlums = (Alum*)malloc(sizeof(Alum) * size);
	listToArray(sortedAlums);
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapify(sortedAlums, size, i);
	}

}

void AlumList::listToArray(Alum* array)
{
	AlumSListType *current = head;
	int i = 0;
	while(current != NULL) {
		array[i++] = *current->getAlum();
		current = current->getNext();
	}
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void AlumList::heapify(Alum arr[], int n, int i)
{
	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2;  // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l].getScore() > arr[largest].getScore())
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r].getScore() > arr[largest].getScore())
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
void AlumList::heapSort(Alum arr[], int n)
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