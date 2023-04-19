#include "Fish.h"

void Fish::Read(std::ostream& ostr, std::istream& istr)
{
	Animal::Read(ostr, istr); //get animal details

	//get fish details
	ostr << endl << "Enter Habitat: ";
	istr >> this->habitat;
	ostr << endl << "Enter Number of Teeth: ";
	istr >> this->teeth;
	ostr << endl << "Enter Number of Fins: ";
	istr >> this->fins;
}

string Fish::getHabitat() {
	return habitat;
}

int Fish::getTeeth() {
	return teeth;
}

int Fish::getFins() {
	return fins;
}