#pragma once
#include <iostream>
using namespace std;
class Animal
{
public:
	enum class eType { Fish = 1, Bird = 2 };
protected:
	string name;
	unsigned int lifespan = 0;
	string color;
public:
	string getName() { return name; }
	void setName(string val) { name = val; }

	int getLifespan() { return lifespan; }
	void setLifespan(unsigned int span) { lifespan = span; }

	string getColor() { return color; }
	void setColor(string col) { color = col; }

	virtual void Read(std::ostream& ostr, std::istream& istr);

	virtual eType getType() = 0; //Pure virtual method
};

