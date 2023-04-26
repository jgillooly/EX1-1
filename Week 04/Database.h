#pragma once
#include "Animal.h"
#include "Fish.h"
#include "Bird.h"
#include <list>
class Database
{
private:
	std::list<std::unique_ptr<Animal>> _animals;
	Animal::eType int2Type(int num);
public:
	const string filename = "testfile.txt";
	std::unique_ptr<Animal> create(Animal::eType type);
	void add(std::unique_ptr<Animal>& animal);
	void displayAll(std::ostream& ostr);
	void display(std::ostream& ostr, string name);
	void display(std::ostream& ostr, Animal::eType type);
	void display(std::ostream& ostr, int num);

	void save(const string filename);
};

