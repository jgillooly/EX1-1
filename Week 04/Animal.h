#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Animal
{
public:
	enum class eType { Undefined = 0, Fish = 1, Bird = 2 };
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
	virtual void Write(std::ostream& ostr);

	virtual void Read(std::ifstream& istr);
	virtual void Write(std::ofstream& ostr);

	virtual eType getType() = 0; //Pure virtual method
	string getTypeString();

	friend bool operator == (const std::unique_ptr<Animal>& animal, const std::string& name) { return animal->getName() == name; }
	friend bool operator == (const std::unique_ptr<Animal>& animal, const Animal::eType& type) { return animal->getType() == type; }
	//
	friend std::istream& operator >> (std::istream& stream, Animal& animal);
	friend std::ostream& operator << (std::ostream& stream, Animal& animal);
	//
	friend std::ifstream& operator >> (std::ifstream& stream, Animal& animal);
	friend std::ofstream& operator << (std::ofstream& stream, Animal& animal);
};

