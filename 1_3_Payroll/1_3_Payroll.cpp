// 1_3_Payroll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;
#include <iostream>

int main()
{
    const unsigned short maxDays = 7;
    const float Tax = 0.1f;


    string name;

    unsigned int uCount = 0; //get
    std::cout << "Hello World!\n";
    unsigned short hours[maxDays]; //get
    float fGrossPay = 0;
    float netPay = 0;
    float payRate = 0; //get
    int totalHours = 0;

    cout << "\nEnter your name: ";
    cin >> name;

    cout << "\nEnter your hourly pay rate: ";
    cin >> payRate;

    cout << "\nEnter number of days worked (max 7): ";
    cin >> uCount;

    for (int i = 0; i < uCount; i++)
    {
        // get values for hours worked
        cout << "\nEnter hours worked for day " << (i + 1) << ": ";
        cin >> hours[i];
    }

    //calc pay and taxes and output
    for (int i = 0; i < size(hours); i++)
    {
        if (hours[i] !=52428) {
            fGrossPay += (hours[i] * payRate);
            totalHours += hours[i];
        }
    }

    cout << "\n" << name << " worked for " << totalHours << " hours at a rate of $" << payRate << " per hour";

    cout << "\nGross pay is: $" << fGrossPay;
    netPay = fGrossPay - (fGrossPay * Tax);
    cout << "\nNet pay is: $" << netPay;

    cout << "\nEnd of app";

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
