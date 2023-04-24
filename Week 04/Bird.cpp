#include "Bird.h"
void Bird::Read(std::ostream& ostr, std::istream& istr) {
	Animal::Read(ostr, istr); //get animal details

	//get bird details
	ostr << endl << "Enter Wingspan: ";
	istr >> this->_wingspan;
	ostr << endl << "Enter Number of Eggs: ";
	istr >> this->_numEggs;
}

void Bird::Write(std::ostream& ostr) {
	Animal::Write(ostr);
	ostr << endl << "Wingspan: " << this->_wingspan;
	ostr << endl << "Number of Eggs: " << this->_numEggs;
}

int Bird::getWingspan() {
	return _wingspan;
}

int Bird::getNumEggs() {
	return _numEggs;
}
