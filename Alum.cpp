#pragma once
#include "stdafx.h"
#include "Alum.h"
#include <iostream>


Alum::Alum(std::string name) 
{
	this->name = name;
}
Alum::Alum(std::string name, float score) 
{
	this->name = name;
	this->score = score;
}


Alum::~Alum()
{
}

std::string Alum::getName() 
{
	return this->name;
}

float Alum::getScore() 
{
	return this->score;
}

void Alum::setScore(float score)
{
	this->score = score;
}

void Alum::print() {
	std::cout << this->name;
	std::cout << " , " << this->score;
}