//#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string delZero(string s){
	string output;
	for (int i = 0; i < s.size(); i++){
		if (s[i] != '0'){
			output += s[i];
		}
	}
	return output;
}

string soundexCode(string &input){
	string output="0" ;
	for (int i = 0; i < input.size(); i++){
		char c = input[i];
		if ((c == 'B' || c == 'F' || c == 'P' || c == 'V') && output[output.size() - 1] != '1'){
			output += "1";
		}
		else if ((c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z') && output[output.size() - 1] != '2'){
			output += "2";
		}
		else if ((c == 'D' || c == 'T') && output[output.size() - 1] != '3'){
			output += "3";
		}
		else if (c == 'L' && output[output.size() - 1] != '4'){
			output += "4";
		}
		else if ((c == 'M' || c == 'N') && output[output.size() - 1] != '5'){
			output += "5";
		}
		else if (c == 'R' && output[output.size() - 1] != '6'){
			output += "6";
		}
		else if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='H' || c=='W' || c=='Y'){
			output += "0";
		}
	}


	return delZero(output);

}

int main(){
	string a;
	while (cin >> a){
		cout << soundexCode(a) << endl;
	}

}

