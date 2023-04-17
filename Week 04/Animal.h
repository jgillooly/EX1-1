#pragma once
#include <iostream>
using namespace std;
class Animal
{
private:
	string name;
	int lifespan;
	string color;
public:
	string getName();
	int getLifespan();
	string getColor();
};

