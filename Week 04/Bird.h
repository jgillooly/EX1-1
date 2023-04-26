#pragma once
#include "Animal.h"
class Bird : public Animal
{
public:
    eType getType() override { return eType::Bird; }

    void Read(std::ostream& ostr, std::istream& istr) override;
    void Write(std::ostream& ostr) override;

    void Read(std::ifstream& istr) override;
    void Write(std::ofstream& ostr) override;
private:
    int _wingspan = 0;
    int _numEggs = 0;
public:
    int getWingspan();
    int getNumEggs();
};

