#pragma once
#include "Animal.h"
class Bird : public Animal
{
public:
    eType getType() override { return eType::Bird; }

    void Read(std::ostream& ostr, std::istream& istr) override;
private:
    int wingspan = 0;
    int numEggs = 0;
public:
    int getWingspan();
    int getNumEggs();
};

