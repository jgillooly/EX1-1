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
        animal->Write(ostr);
    }
}

void Database::display(std::ostream& ostr, string name) {
    for (std::unique_ptr<Animal>& animal : this->_animals) {
        if (animal->getName().find(name) != string::npos) {
            animal->Write(ostr);
        }
    }
}

void Database::display(std::ostream& ostr, Animal::eType type) {
    for (std::unique_ptr<Animal>& animal : this->_animals) {
        if (animal->getType() == type) {
            animal->Write(ostr);
        }
    }
}

void Database::display(std::ostream& ostr, int num) {
    display(ostr, int2Type(num));
}

void Database::save(const string filename) {
    //Open file
    std::ofstream output(filename, std::ofstream::out | std::ofstream::app); //Bitwise OR
    if (output.is_open() == true) {
        for (std::unique_ptr<Animal>& animal : this->_animals) {
            animal->Write(output);
        }
    }
}
