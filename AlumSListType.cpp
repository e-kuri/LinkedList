#include "stdafx.h"
#include "AlumSListType.h"


AlumSListType::AlumSListType(AlumSListType *next, AlumSListType *prev, Alum* alum)
{
	this->next = next;
	this->prev = prev;
	this->alum = alum;
}


AlumSListType::~AlumSListType()
{
}

Alum* AlumSListType::getAlum()
{
	return this->alum;
}

AlumSListType* AlumSListType::getNext()
{
	return this->next;
}

AlumSListType* AlumSListType::getPrev()
{
	return this->prev;
}

void AlumSListType::setNext(AlumSListType* next)
{
	this->next = next;
}

void AlumSListType::setPrev(AlumSListType* prev)
{
	this->prev = prev;
}