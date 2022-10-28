/*LinkedList ,
	Mohammad Naseri 9602813
*/
#include "stdafx.h"
#include <iostream>
using namespace std;


class Node
{
	Node *next;
	int data;
	friend class LinkedList;
public:
	Node(int d){
		next = NULL;
		data = d;
	}
	Node(){
		next = NULL;
	}
	~Node();
};

//=========================================================================

class LinkedList
{
	Node *head, *tail;

public:

	void append(int d){
		Node *tmp = new Node(d);
		if (head == NULL){
			head = tmp;
			tail = tmp;
		}
		else{
			tail->next = tmp;
			tail = tmp;

		}
	}

//------------------------------------------------------

	void print(){
		Node *tmp = new Node();
		tmp = head;
		cout << "[";
		while (tmp != NULL){
			cout <<" " << tmp->data<<" ";
			tmp = tmp->next;
		}
		cout << "]" << endl;
	}

//-----------------------------------------------------

	//returns length of the list
	int length(){
		int count = 0;
		Node *tmp = new Node();
		tmp = head;
		while (tmp != NULL){
			count++;
			tmp = tmp->next;
		}
		return count;
	}

//------------------------------------------------------

	//returns the index of a Node that its data equals input (indexes Are started from zero [0])
	int searchByValue(int val){
		Node *tmp = new Node();
		tmp = head;
		for (int i = 0; i < this->length() ; i++){
			if (tmp->data == val){
				return i;
			}
			tmp = tmp->next;
		}
		cout << "	Value is Not in List [Output Error] : ";
		return NULL;
	}

//------------------------------------------------------

	//returns the value of the node in index i (indexes are started from zero [0])
	int get(int indx){
		Node *tmp = new Node();
		tmp = head;
		for (int i = 0; i < this->length(); i++){
			if (indx == i){
				return tmp->data;
			}
			tmp = tmp->next;
		}
		cout << "	Index Out Of Range [Output Error] : ";
		return NULL;
	}

//------------------------------------------------------

	//goes forward in list and saves the previous and current node everytime , when at position prev->next = tmp & tmp->next=current ;
	void insert(int pos, int number) {
		if (pos > this->length()){
			cout << "	Index Out Of Range [Error] " << endl;
		}
		else if (this->head == NULL) {
			cout << "	 FAILURE !"<<endl;
		}
		else
		{
			Node *temp = new Node;
			temp->next = NULL;
			temp->data = number;

			Node *curr = new Node;
			Node *prev = new Node;

			curr = head;
			for (int i = 1; i < pos+1; i++) {
				prev = curr;
				curr = curr->next;

			}
			prev->next = temp;
			temp->next = curr;
		}
	}

//------------------------------------------------------

	//deleting a node by its value , algorithm is as insertion , at the end prev.next = curr.next ;
	void deletbyvalue(int data){
		int pos = this->searchByValue(data);
		if (this->searchByValue((data))==NULL){
			cout << "	Value is Not in List [Error] " << endl;
		}
		else if (this->head == NULL) {
			cout << "	FAILURE !"<< endl;
		}
		else
		{
			Node *curr = new Node;
			Node *prev = new Node;
			curr = head;
			for (int i = 1; i < pos + 1; i++) {
				prev = curr;
				curr = curr->next;

			}
			prev->next = curr->next;
		}
	}

//------------------------------------------------------

	//deletin by index , algorithm is still the same as insertion and delet by value .
	void delete(int indx){
		if (this->head == NULL) {
			cout << "	FAILURE !"<< endl;
		}
		else if (indx > this->length()){
			cout << "	Index Out Of Range [Error] "<<endl;
		}
		else
		{
			Node *curr = new Node;
			Node *prev = new Node;
			curr = head;
			for (int i = 1; i < indx + 1; i++) {
				prev = curr;
				curr = curr->next;

			}
			prev->next = curr->next;
		}
	}

//------------------------------------------------------

	void edit(int indx, int value){
		Node *tmp = new Node();
		tmp = head;
		if (indx > this->length()){
			cout << "	Index Out Of Range [Error] " << endl;
		}
		else{
			for (int i = 0; i < indx + 1; i++){
				if (indx == i){
					tmp->data = value;
				}
				tmp = tmp->next;
			}
		}
	}
//------------------------------------------------------

	LinkedList(){

		head = NULL;
		tail = NULL;
	}

//------------------------------------------------------

};

int main(){
	LinkedList ll;
	ll.append(1);
	ll.append(2);
	ll.append(3);
	ll.append(4);
	ll.append(5);
	ll.append(6);
	ll.append(7);
	ll.print();
	cout << ll.length()<<endl;
	cout<<ll.searchByValue(4)<<endl;
	cout << ll.get(4) << endl;
	ll.insert(3, 12);
	ll.print();
	cout << ll.searchByValue(12) << endl;
	cout << ll.get(3) << endl;
	ll.deletbyvalue(12);
	ll.print();
	cout << ll.searchByValue(12) << endl;
	cout << ll.get(3) << endl;
	ll.delete(3);
	ll.print();
	ll.edit(12, 12);
	ll.print();
	cout<<ll.get(3);
	int a;
	cin >> a;
	return 0;
}


