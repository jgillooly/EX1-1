#include "Database.h"
using namespace std;

std::unique_ptr<Animal> Database::create(Animal::eType type) {
    Animal* animal = nullptr;
    switch (type) {
    case Animal::eType::Bird:
        animal = new Bird;
        break;
    case Animal::eType::Fish:
        animal = new Fish;
        break;
    }

    return std::unique_ptr<Animal>{animal};
}

Animal::eType Database::int2Type(int num) {
    switch (num) {
    case 1:
        return Animal::eType::Fish;
    case 2:
        return Animal::eType::Bird;
    default:
        return Animal::eType::Undefined;
    }
}

void Database::add(std::unique_ptr<Animal>& animal) {
    _animals.push_back(std::move(animal));
    cout << endl << "***List Size = " << this->_animals.size();
}

void Database::displayAll(std::ostream& ostr) {
    for (std::unique_ptr<Animal>& animal : this->_animals) {
        ostr << *animal;
    }
}

void Database::display(std::ostream& ostr, string name) {
    for (std::unique_ptr<Animal>& animal : this->_animals) {
        if (animal->getName().find(name) != string::npos) {
            ostr << *animal;
        }
    }
}

void Database::display(std::ostream& ostr, Animal::eType type) {
    for (std::unique_ptr<Animal>& animal : this->_animals) {
        if (animal == type) {
            ostr << *animal;
        }
    }
}

void Database::display(std::ostream& ostr, int num) {
    display(ostr, int2Type(num));
}

void Database::removeAll() {
    _animals.clear();
}

void Database::save(const string& filename) {
    //Open file
    std::ofstream output(filename, std::ofstream::out | std::ofstream::app); //Bitwise OR
    if (output.is_open() == true) {
        for (std::unique_ptr<Animal>& animal : this->_animals) {
            output << *animal;
        }

    }
    if (output.is_open() == true) output.close();
}

void Database::load(const string& filename) {
    std::ifstream input(filename);
    int iType = 0;
    this->removeAll();
    std::unique_ptr<Animal> animal = nullptr;
    

    if (input.is_open() == true) {
        while (!input.eof()) {
            input >> iType;
            if (input.fail()) break;
            animal = this->create(static_cast<Animal::eType>(iType));
            input >> *animal;
            this->add(animal);
            //switch (iType) {
            //case 1:
            //    animal = this->create(Animal::eType::Fish);
            //    break;
            //case 2:
            //    animal = this->create(Animal::eType::Bird);
            //    break;
            //} //End switch
        } //End While
    } //End if

    if (input.is_open() == true) input.close();
}
