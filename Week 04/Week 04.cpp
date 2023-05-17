// Week 04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyInput.h"
#include "Bird.h"
#include "Fish.h"
#include "Database.h"
using namespace std;

int main()
{
    std::cout << "Week 04 Hello World!\n";

    MyInput input;
    Database db;
    std::unique_ptr<Animal> animal;
    int iMenu = 0;
    string name = "";
    Animal::eType type;
    int confirm = 0;

    while (iMenu != 8) {
        cout << endl << "Enter a Menu Option: ";
        cout << endl << "1) Add an Animal";
        cout << endl << "2) Display all Animals";
        cout << endl << "3) Display by Name";
        cout << endl << "4) Display by Type";
        cout << endl << "5) Remove All";
        cout << endl << "6) Load from File";
        cout << endl << "7) Save to File";
        cout << endl << "8) Quit" << endl;

        iMenu = input.GetUserInt(1, 8);

        switch (iMenu) {
        case 1: //New Animal
            int iType;
            cout << "1) Fish" << endl << "2) Bird" << endl;
            iType = input.GetUserInt(1, 2);
            switch (iType) {
            case 1:
                animal = db.create(Animal::eType::Fish);
                break;
            case 2:
                animal = db.create(Animal::eType::Bird);
                break;
            }//inner switch
            animal->Read(cout, cin);
            db.add(animal);
            break;
        case 2: //Display Animals
            db.displayAll(cout);
            break;
        case 3: //Display by Name
            cout << endl << "Enter a name to display by: ";
            cin >> name;
            db.display(cout, name);
            break;
        case 4: //Display by Type
            cout << endl << "Choose a type to display by: ";
            cout << endl << "1) Fish" << endl << "2) Bird" << endl;
            type = (input.GetUserInt(1, 2) == 1 ? Animal::eType::Fish : Animal::eType::Bird);
            db.display(cout, type);
            break;
        case 5: //Clear database
            cout << endl << "Are you sure? (1:Yes/2:No)";
            confirm = input.GetUserInt(1, 2);
            if (confirm == 1) {
                db.removeAll();
                cout << endl << "Database Cleared";
            }
        case 6: //Load from file
            db.load(db.filename);
            cout << endl << "Load successful(?)";
            break;
        case 7: //Save to file
            db.save(db.filename);
            cout << endl << "Save successful(?)";
            break;
        }//outer switch

    }//while loop
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
