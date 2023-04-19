#include "Bird.h"
void Bird::Read(std::ostream& ostr, std::istream& istr) {
	Animal::Read(ostr, istr); //get animal details

	//get bird details
	ostr << endl << "Enter Wingspan: ";
	istr >> this->wingspan;
	ostr << endl << "Enter Number of Eggs: ";
	istr >> this->numEggs;
}