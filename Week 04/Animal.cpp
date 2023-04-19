#include "Animal.h"
void Animal::Read(std::ostream& ostr, std::istream& istr) {
	ostr << endl << "Enter Animal Name: ";
	istr >> this->name;
	ostr << endl << "Enter Animal Lifespan: ";
	istr >> this->lifespan;
}
