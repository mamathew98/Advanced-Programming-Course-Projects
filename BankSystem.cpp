// BankSystem.cpp : Defines the entry point for the console application.
// As 5 
// Mohammad Naseri 9602813
//purpose is to creat 3 classes that have inhertitance Customer->Depositor->Borrower 
//The main process is on the borrower class which has inheritance from both Customer and Depositor classes

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Customer {
	string name;
	double phoneNumber;
	
public:
	void setName(string s) {
		this->name = s;
	}
	void setPhoneNumber(double d) {
		this->phoneNumber = d;
	}
	string getName() { return this->name; }
	double getPhoneNumber() { return this->phoneNumber; }
};

// =================================================

class Depositor:public Customer {
	static double accNumber;
	double balance;
public:
	void setAccNumber() { this->accNumber = accNumber++; }
	void setBalance(double d) {this->balance = d;}
	double getBalance() { return this->balance; }
	double getAccNumber() { return this->accNumber; }
	void deposit(double d) {
		this->balance += d;
		cout << "New Balance is : " << this->getBalance << endl;
	}
	//taking some amount of money 
	void withdraw(double d) {
		if (d > this->balance) {
			cout << "The Balance is Not Enough" << endl;
		}
		else{
			this->balance -= d;
			cout << "New Balance is : " << this->getBalance << endl;
		}
	}
	double getBalance() {
		return this->balance;
	}

};

//============================================================

class Borrower:public Depositor {
	static double loanNumber;
	double loanAmount = 0;
	double paid = 0;
	double remaining = loanAmount - paid;
public:
	//difining the borrower 
	void define() {
		cout << "Plz Enter Name : " << endl;
		string name;
		cin >> name;
		this->setName(name);
		cout << "plz Enter Phone Number : " << endl;
		double pn;
		cin >> pn;
		this->setPhoneNumber(pn);
		this->setAccNumber();
		cout << "plz Enter Balance : " << endl;
		double bal;
		cin >> bal;
		this->setBalance(bal);
		cout << "Plz Enter Loan Amount : " << endl;



	}
	//paying back a part of loaned money
	void payBack(double d) {
		if (loanAmount <= 0) {
			cout << "The Loan Amount Has Been Already Paid" << endl;
		}
		else{
			this->paid += d;
			cout << "New Remaining : " << remaining << endl; 
		}	
	}
	//borrowing money 
	void loan(double d,double ln) {
		this->loanAmount += d;
		this->loanNumber = ln;
		cout << "New Loan Amount is : " << this->loanAmount << endl;
	}

};


int main()
{
	//make objects from every class and do process in them ...
    return 0;
}

