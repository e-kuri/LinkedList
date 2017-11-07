// LinkedList.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "AlumList.h"
#include "Alum.h"
#include "AlumSListType.h"


int main()
{
	AlumList list = AlumList();
	Alum alum1 = Alum("Pepe", 10.0);
	Alum alum2 = Alum("Tonio", 8.0);
	Alum alum3 = Alum("Oscar", 9.0);
	list.addAlum(alum1);
	list.addAlum(alum2);
	list.addAlum(alum3);
//	list.printListbyScore();
	list.print();
	getchar();
    return 0;
}

