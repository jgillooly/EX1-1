#include "MyInput.h"
int MyInput::GetUserInt(string prompt, unsigned short low, unsigned short high) {
	int iTemp;
	do {
		cout << prompt;
		cout << endl << "Enter a number between " << low << " and " << high << endl;
		cin >> iTemp;
		if (!cin.good()) {
			cin.clear();
			cin.ignore();
			cout << endl << "!!! Improper input !!!";
			iTemp = low - 1;
		}
	} while (iTemp > high || iTemp < low);
	return iTemp;
}

int MyInput::GetUserInt(unsigned short low, unsigned short high){
	return GetUserInt("", low, high);
}