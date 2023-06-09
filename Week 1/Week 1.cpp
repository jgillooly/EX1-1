// Week 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Week 01 - Hello World!\n";

    int ival1 = -1;
    int ival4 = 34;
    short shval2 = 3;
    long lval3 = 1234567890;
    float fval5 = 3.5;
    char chval1 = 'a';

    std::cout << "ival1 = ";
    std::cout << ival1 << " address = " << &ival1;
    std::cout << "\nshval2 = " << shval2 << " address = " << &shval2;
    std::cout << "\nival4 = " << ival4 << " address = " << &ival4;
    
    std::cout << "\n***** Size of char = " << sizeof(chval1);
    std::cout << "\n***** Size of short = " << sizeof(shval2);
    std::cout << "\n***** Size of int = " << sizeof(ival1);

    int* iptr = NULL;
    iptr = &ival1;
    long* lptr = &lval3;

    std::cout << "\nValue of ptr var = " << iptr;
    std::cout << "\niptr addresss = " << &iptr;
    std::cout << "\nsize of iptr = " << sizeof(iptr);
    std::cout << "\nvalue iptr points to is " << *(lptr + 1);

    // heap memory
    char* chTemp = NULL;
    chTemp = (char*)malloc(20);
    memset(chTemp, '\0', 20);
    //memset(chTemp, NULL, 20);
    //do stuff with the memory then free it
    free(chTemp);
    chTemp = NULL; //good practice

    std::cout << "\n\nEND OF PROGRAM";


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
