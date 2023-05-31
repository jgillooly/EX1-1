// Week08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "List.h"

int main() {
	std::cout << "list\n";
	nc::list<int> numbers{ 12, 78, 12, 34, 9 };
	numbers.push_back(10);
	numbers.push_front(8);
	numbers.write(std::cout);
	std::cout << "\ncopy\n";
	nc::list<int> copy;
	copy = numbers;
	copy.pop_front();
	copy.pop_back();
	copy.pop_back();
	copy.write(std::cout);
	std::cout << "\nremove\n";
	copy.remove(12);
	copy.write(std::cout);
	//std::cout << "resize\n";
	//copy.resize(10, 99); <- NO
	copy.write(std::cout);
	std::cout << "\nreverse\n";
	numbers.reverse();
	numbers.write(std::cout);
	std::cout << "front: " << numbers.front() << std::endl;
	std::cout << "back: " << numbers.back() << std::endl;
	std::cout << "size: " << numbers.size() << std::endl;
	std::cout << "empty: " << numbers.empty() << std::endl;
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
