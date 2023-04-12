// 3_2_MemoryReview.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyConfig.h"
using namespace std;
struct Person
{
	char name[32];
	int id;
};

void Square(int& num) {
	num *= num;
}

void Double(int* num) {
	*num = (*num) * 2;
}

int main()
{
	Config myConfig;
	myConfig.Version.major = 1;
	cout << "HELLO WORLD" << endl;
	// ** REFERENCE **
	//
	// declare an int variable and set the value to some number (less than 10)
	int number = 5;
	// declare a int reference and set it to the int variable above
	int& intRef = number;
	// output the int variable
	cout << number << endl;
	// set the int reference to some number
	intRef = 7;
	// output the int variable
	cout << number << endl;
	// what happened to the int variable when the reference was changed? (insert answer)
	// it was also changed
	// output the address of the int variable
	cout << &number << endl;
	// output the address of the int reference
	cout << &intRef << endl;
	// are the addresses the same or different? (insert answer)
	// They are the same
	// ** REFERENCE PARAMETER **
	//
	// create a function above main() called Square that takes in an int parameter
		// in the function, multiply the int parameter by itself and assign it back to the parameter(i = i * i)
		// call the Square function with the int variable created in the REFERENCE section
	Square(number);
		// output the int variable to the console
	cout << number << endl;
		// !! notice how the variable has not changed, this is because we only passed the value to the function !!
		// change the Square function to take a int reference
		// !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
		// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""
		// ** POINTER VARIABLE **
		//
		// declare an int pointer, set it to nullptr (it points to nothing)
	int* iPtr = nullptr;
		// set the int pointer to the address of the int variable created in the REFERENCE section
	iPtr = &number;
		// output the value of the pointer
	cout << iPtr << endl;
		// what is this address that the pointer is pointing to? (insert answer)
		// The memory address of the original integer
		// output the value of the object the pointer is pointing to (dereference the pointer)
	cout << *iPtr << endl;
		// ** POINTER PARAMETER **
		//
		// create a function above main() called Double that takes in an int pointer parameter
		// in the function, multiply the int pointer parameter by 2 and assign it back to the parameter(i = i * 2)
		// !! make sure to dereference the pointer to set the value and not set the address !!
		// call the Double function with the pointer created in the POINTER VARIABLE section
	Double(iPtr);
	//Double(&number);
		// output the dereference pointer
	cout << *iPtr << endl;
		// output the int variable created in the REFERENCE section
	cout << number << endl;
		// did the int variable's value change when using the pointer?
		// YES
		// 
		// ** ALLOCATION/DEALLOCATION **
		// create an int pointer that points at an int allocated on the heap, set the allocated int value to some number
	int* heapPtr = new int();
	*heapPtr = 5;
		// output the pointer value, this should be the address of the int allocated on the heap
	cout << heapPtr << endl;
		// output the dereference pointer
	cout << *heapPtr << endl << endl;
		// deallocate the int pointer to free up the memory
	delete heapPtr;
		// create an int pointer that points at an array of ints allocated on the heap, the array size should be 4 - 6
	int* aryPtr = new int[6];
		// use a for loop and set each int in the array to a random number (use => rand() % 10 to get a random number
	srand(time(NULL));
	for (int i = 0; i < 6; i++)
	{
		int number = (rand() % 10);
		cout << number << endl;
		*(aryPtr+(i)) = number;
	}
	cout << endl;
		// use a for loop and output each of the ints in the array
	for (int i = 0; i < 6; i++)
	{
		cout << *(aryPtr + (i)) << endl;
	}
		// use a for loop and output the address of each of the ints in the array
	for (int i = 0; i < 6; i++)
	{
		cout << aryPtr + (i) << endl;
	}
		// deallocate the int pointer to free up the memory block (remember it's an array)
	delete aryPtr;
		// ** STRUCTURE **
		//
		// create a Person pointer that points at an array of Persons allocated on the heap, the array size should be 2
	Person* people = new Person[2];
		// read in a name from the console and set it to the person name, do this for the id also, do this for both Persons
	cout << "Enter a name for Person 1: ";
	cin >> people->name;
	cout << "Enter an id for Person 1: ";
	cin >> people->id;
	cout << "Enter a name for Person 2: ";
	cin >> (people+1)->name;
	cout << "Enter a id for Person 2: ";
	cin >> (people + 1)->id;
		// use a for loop and output the name and id of each person in the array
	for (int i = 0; i < 2; i++)
	{
		Person* ptr = (people + i);
		cout << (ptr)->name << " " << (ptr)->id << endl;
	}
		// deallocate the person pointer to free up the memory block (remember it's an array)
	delete[2] people;
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
