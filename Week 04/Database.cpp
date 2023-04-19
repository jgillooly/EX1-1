#include "Database.h"

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
