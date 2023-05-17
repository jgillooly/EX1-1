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

//Read from file
void Animal::Read(std::ifstream& istr) {
	istr >> this->name;
	istr >> this->lifespan;
}

//Write to file
void Animal::Write(std::ofstream& ostr) {
	ostr << (int)this->getType() << endl; // must be first record
	ostr << this->name << endl;
	ostr << this->lifespan << endl;
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

std::istream& operator >> (std::istream& stream, Animal& animal) {
	animal.Read(std::cout, stream);
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Animal& animal) {
	animal.Write(stream);
	return stream;
}

std::ifstream& operator >> (std::ifstream& stream, Animal& animal) {
	animal.Read(stream);
	return stream;
}

std::ofstream& operator << (std::ofstream& stream, Animal& animal) {
	animal.Write(stream);
	return stream;
}
