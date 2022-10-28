#include <iostream>
#include <string>
#include "stdafx.h"
#include "Contacts.h"
using namespace std;


Contacts::Contacts()
{
}
void Contacts::setName(string name){
	Name = name;
}
void Contacts::getName(){
	cout << "Name : " << Name;
}
void Contacts::setNum(double num){
	Number = num;
}
void Contacts::getNum(){
	cout << Name << " : " << Number << endl;
}
Contacts::~Contacts()
{
	cout << "Contact " << Name << " Has been Deleted" << endl;
}
