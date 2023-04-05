#pragma once
class Employee
{
public:
	static const int MAXDAYS = 7;
	char name[35];
	int age = 0;
	const float Tax = 0.1;
	float hoursPerDay[MAXDAYS];
	int  uCount;
	float payRate;
public:
	Employee();
	void Read(int num);
	void Write();
private:
	void printName();
};

