#pragma once
#include "Alum.h"

class AlumSListType
{
public:
	AlumSListType(AlumSListType *next, AlumSListType *prev, Alum* alum);
	~AlumSListType();
	void setNext(AlumSListType *next);
	void setPrev(AlumSListType *prev);
	AlumSListType* getNext();
	AlumSListType* getPrev();
	Alum& getAlum();

private:
	AlumSListType *next;
	AlumSListType *prev;
	Alum *alum;
};

