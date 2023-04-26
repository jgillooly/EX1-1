#include "Bird.h"

//Read from Console
void Bird::Read(std::ostream& ostr, std::istream& istr) {
	Animal::Read(ostr, istr); //get animal details

	//get bird details
	ostr << endl << "Enter Wingspan: ";
	istr >> this->_wingspan;
	ostr << endl << "Enter Number of Eggs: ";
	istr >> this->_numEggs;
}

//Write to Console
void Bird::Write(std::ostream& ostr) {
	Animal::Write(ostr);
	ostr << endl << "Wingspan: " << this->_wingspan;
	ostr << endl << "Number of Eggs: " << this->_numEggs;
}

//Read from file
void Bird::Read(std::ifstream& istr) {
	Animal::Read(istr);
	istr >> this->_wingspan;
	istr >> this->_numEggs;
}

//Write to file
void Bird::Write(std::ofstream& ostr) {
	Animal::Write(ostr);
	ostr << this->_wingspan << endl;
	ostr << this->_numEggs << endl;
}

int Bird::getWingspan() {
	return _wingspan;
}

int Bird::getNumEggs() {
	return _numEggs;
}
