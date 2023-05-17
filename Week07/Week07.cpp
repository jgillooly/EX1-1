// Week07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "vector.h"
#include <iostream>
template <typename T>
void Display(const nc::vector<T>& v) {
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}
int main() {
	std::cout << "vector\n";
	nc::vector<int> numbers{ 43, 23, 56, 7, 16 };
	numbers[0] = 84;
	numbers.push_back(99);
	Display(numbers);
	std::cout << "copy\n";
	nc::vector<int> copy;
	copy = numbers;
	copy.pop_back();
	copy.pop_back();
	Display(copy);
	std::cout << "swap\n";
	numbers.swap(copy);
	Display(numbers);
	Display(copy);
	std::cout << "clear\n";
	copy.clear();
	Display(copy);
	std::cout << "assignment\n";
	copy = numbers;
	Display(numbers);
	std::cout << "resize\n";
	numbers.resize(10, 5);
	numbers.reserve(20);
	Display(numbers);
	std::cout << "front: " << numbers.front() << std::endl;
	std::cout << "back: " << numbers.back() << std::endl;
	std::cout << "size: " << numbers.size() << std::endl;
	std::cout << "max size: " << numbers.max_size() << std::endl;
	std::cout << "capacity: " << numbers.capacity() << std::endl;
	std::cout << "empty: " << numbers.empty() << std::endl;
	std::cout << "data: " << numbers.data() << std::endl;
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
