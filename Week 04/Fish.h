#pragma once
#include "Animal.h"
class Fish : public Animal
{
public:
    eType getType() override { return eType::Bird; }

    void Read(std::ostream& ostr, std::istream& istr) override;
private:
    string habitat;
    int teeth = 0;
    int fins = 0;
public:
    string getHabitat();
    int getTeeth();
    int getFins();
};

