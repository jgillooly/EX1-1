#include "Fish.h"

//Read from Console
void Fish::Read(std::ostream& ostr, std::istream& istr)
{
	Animal::Read(ostr, istr); //get animal details

	//get fish details
	ostr << endl << "Enter Habitat: ";
	istr >> this->_habitat;
	ostr << endl << "Enter Number of Teeth: ";
	istr >> this->_teeth;
	ostr << endl << "Enter Number of Fins: ";
	istr >> this->_fins;
}

//Write to Console
void Fish::Write(std::ostream& ostr) {
	Animal::Write(ostr);
	ostr << endl << "Habitat: " << this->_habitat;
	ostr << endl << "Number of Teeth: " << this->_teeth;
	ostr << endl << "Number of Fins: " << this->_fins;
}

//Read from file
void Fish::Read(std::ifstream& istr) {
	Animal::Read(istr);
	istr >> this->_habitat;
	istr >> this->_teeth;
	istr >> this->_fins;
}

//Write to file
void Fish::Write(std::ofstream& ostr) {
	Animal::Write(ostr);
	ostr << this->_habitat << endl;
	ostr << this->_teeth << endl;
	ostr << this->_fins << endl;
}

string Fish::getHabitat() {
	return _habitat;
}

int Fish::getTeeth() {
	return _teeth;
}

int Fish::getFins() {
	return _fins;
}