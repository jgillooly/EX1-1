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
