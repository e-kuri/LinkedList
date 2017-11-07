#pragma once
#include<string>
class Alum
{
public:
	Alum(std::string name);
	Alum(std::string name, float score);
	~Alum();
	float getScore();
	void setScore(float score);
	std::string getName();

private:
	std::string name;
	float score;

};

