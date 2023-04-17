#pragma once
#include "Animal.h"
class Fish :
    public Animal
{
private:
    string habitat;
    int teeth;
    int fins;
public:
    string getHabitat();
    int getTeeth();
    int getFins();
};

