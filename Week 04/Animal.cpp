#include "Animal.h"
//Read from console
void Animal::Read(std::ostream& ostr, std::istream& istr) {
	ostr << endl << "Enter Animal Name: ";
	istr >> this->name;
	ostr << endl << "Enter Animal Lifespan: ";
	istr >> this->lifespan;
}

//Write to console
void Animal::Write(std::ostream& ostr) {
	ostr << endl << "-----------------";
	ostr << endl << "Name: " << this->name;
	ostr << endl << "Type: " << this->getTypeString();
	ostr << endl << "Lifespan: " << this->lifespan;
}

//Convert Type enum to String
string Animal::getTypeString() {
	switch (this->getType()) {
	case eType::Bird:
		return "Bird";
		break;
	case eType::Fish:
		return "Fish";
		break;
	default:
		return "Undefined";
		break;
	}
}
