#include <iostream>
#include <string>
#include "Contacts.h"
#include <vector>
using namespace std;

class PhoneBook{
public:
	vector<Contacts> phonebook;
	//add a new conact
	void addContact(string contact_name, double contact_number){
		Contacts newContact;
		newContact.setName(contact_name);
		newContact.setNum(contact_number);
		phonebook.push_back(newContact);

	}
	//=========================================================================================
	//show all contacts saved in phonebook
	void showAllContact(){
		for (int i = 0; i < phonebook.size(); i++){
			cout << phonebook[i].getName << " : " << phonebook[i].getNum << "\n";
		}
	}
	//=========================================================================================
	//delet a contact from phonebook
	void deletContact(string contact_name){
		int found = 0;
		for (int i = 0; i < phonebook.size(); i++){
			if (phonebook[i].getName == contact_name){
				phonebook.erase(phonebook.begin() + i);
				found++;
			}
		}
		if (found == 0){ cout << "Contact was not found" << endl; }
	}
	//==========================================================================================
	//search in contacts
	void findContact(string contact_name){
		int found = 0;
		for (int i = 0; i < phonebook.size(); i++){
			if (phonebook[i].getName == contact_name){
				cout << " Contact Number is : " << phonebook[i].getNum << endl;
				found++;
			}

		}
		if (found == 0){ cout << "Contat was not found" << endl; }
	}
	//==========================================================================================
	//editing contact
	void editContact(string contact_name, string newName, double newNum){
		int found = 0;
		for (int i = 0; i < phonebook.size(); i++){
			if (phonebook[i].getName == contact_name){
				phonebook[i].setName(newName);
				phonebook[i].setNum(newNum);
			}

		}
	};


	//==========================================================================================================
	//run the input that user choose as code
	void runCode(int c, PhoneBook pb){
		string contact_name;
		double contact_num;
		if (c == 2){
			cout << "Plz Enter ur Contact Name : " << "\n";
			cin >> contact_name;
			cout << "Plz Enter ur Contact Number : " << "\n";
			cin >> contact_num;
			pb.addContact(contact_name, contact_num);
		}
		if (c == 1){
			pb.showAllContact;
		}
		if (c == 3){
			cout << "Plz Enter ur Contact Name : " << "\n";
			cin >> contact_name;
			pb.findContact(contact_name);
		}
		if (c == 4){
			cout << "Plz Enter ur Contact Name : " << "\n";
			cin >> contact_name;
			pb.deletContact(contact_name);
		}
		if (c == 5){
			string newName;
			double newNum;
			cout << "Plz Enter ur Current Contact Name : " << endl;
			cin >> contact_name;
			pb.findContact(contact_name);
			cout << "Plz Enter Ur New Name : " << endl;
			cin >> newName;
			cout << "Plz Enter Ur New Number : " << endl;
			cin >> newNum;
			pb.editContact(contact_name, newName, newNum);
		}

	}

	int main(){
		PhoneBook pb;
		int code;
		cout << " Plz Choose What U Want To Do " << "\n" << "1.Show All Contacts" << "\n" << "2.Add a New Contact" << "\n" << "3.Search in Contacts"
			<< "\n" << "4.Delet a Contact" << "\n" << "5.Edit a Contact" << endl;
		cin >> code;
		runCode(code,pb);
	}