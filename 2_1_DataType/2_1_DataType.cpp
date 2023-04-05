// 2_1_DataType.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;
#include <iostream>
#include "Employee.h"

int main()
{
    std::cout << "2_1_DataTypes Hello World!\n";
    const unsigned short MAXEMP = 20;
    unsigned short empAmt = 0;
    
    Employee workers[MAXEMP];

    cout << "\nEnter number of employees: ";
    cin >> empAmt;

    if (empAmt > MAXEMP) empAmt = MAXEMP;



    for (int i = 0; i < empAmt; i++)
    {
        // call read for each employee
        workers[i].Read(i+1);
    }

    for (int i = 0; i < empAmt; i++)
    {
        // call read for each employee
        workers[i].Write();
        cout << "\n";
    }

    /*
    workers[0].age = 23;

    Employee* empPtr = new Employee(); // heap
    empPtr->age = 42;

    void* ptr = malloc(20);
    int* intPtr = new int;
    *intPtr = 42;
    printf("\n hex %00.x", *intPtr);
    printf("\n hex %00.x", *(intPtr+1));

    //do stuff with heap
    //cout << sizeof(Employee);
    delete empPtr;
    delete intPtr;
   
    //!!!! I WILL NEED THIS LATER !!!!
    cout << "\n size 1: " << (sizeof(workers)/sizeof(workers[0]));
    cout << "\n size 2: " << std::size(workers);
     */


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
