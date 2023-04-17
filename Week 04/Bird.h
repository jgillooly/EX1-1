#pragma once
#include "Animal.h"
class Bird :
    public Animal
{
private:
    int wingspan;
    int numEggs;
private:
    int getWingspan();
    int getNumEggs();
};

