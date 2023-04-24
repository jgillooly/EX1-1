#pragma once
#include "Animal.h"
class Fish : public Animal
{
public:
    eType getType() override { return eType::Fish; }

    void Read(std::ostream& ostr, std::istream& istr) override;
    void Write(std::ostream& ostr) override;
private:
    string _habitat;
    int _teeth = 0;
    int _fins = 0;
public:
    string getHabitat();
    int getTeeth();
    int getFins();
};