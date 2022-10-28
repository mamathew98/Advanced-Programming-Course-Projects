#pragma once
#include <iostream>
#include <string>
using namespace std;

class Contacts
{
public:
	Contacts();
	~Contacts();
	void setName(string);
	void getName();
	void setNum(double);
	void getNum();

private:
	double Number;
	string Name;


};

