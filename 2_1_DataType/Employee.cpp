#include "Employee.h"
#include <cstddef>
#include <corecrt_memory.h>
#include <string>
#include <iostream>
using namespace std;

Employee::Employee() {
	// put constructor code here
	memset(&name, NULL, sizeof(name));
	memset(&hoursPerDay, NULL, sizeof(hoursPerDay));
}

Employee::~Employee() {

}
void Employee::Read(int num) {
	//put read code here
    
    string nameS = "";
    cout << "\nEnter name for employee number " << num << ": ";
    cin >> nameS;
    for (int i = 0; i < nameS.size(); i++)
    {
        name[i] = nameS.at(i);
    }

    cout << "\nEnter your hourly pay rate: ";
    cin >> payRate;

    cout << "\nEnter number of days worked (max 7): ";
    cin >> uCount;

    for (int i = 0; i < uCount; i++)
    {
        // get values for hours worked
        cout << "\nEnter hours worked for day " << (i + 1) << ": ";
        cin >> hoursPerDay[i];
    }
}

void Employee::printName() {
    for (char c : name)
    {
        if (c != NULL) {
            cout << c;
        }
        else {
            break;
        }
    }
}
void Employee::Write() {
	//put write code here
    float fGrossPay = 0;
    float netPay = 0;
    int totalHours = 0;
    for (int i = 0; i < size(hoursPerDay); i++)
    {
        if (hoursPerDay[i] != NULL) {
            fGrossPay += (hoursPerDay[i] * payRate);
            totalHours += hoursPerDay[i];
        }
    }

    cout << "\n" << name << " worked for " << totalHours << " hours at a rate of $" << payRate << " per hour";

    cout << "\nGross pay is: $" << fGrossPay;
    netPay = fGrossPay - (fGrossPay * Tax);
    cout << "\nNet pay is: $" << netPay;
}