//#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string input){
	if (input == string(input.rbegin(), input.rend())) {
		return true;
	}
	return false;
}

string makePalindrome(string S,string tmp){
	if (isPalindrome(S)){
		string ans = tmp + S + string(tmp.rbegin(),tmp.rend());
		return ans;
	}
	else{
		tmp += S[0];
		return makePalindrome(S.substr(1, S.size()), tmp);
	}
}

int main(){
	string S;
	//cout << "plz enter string : " << endl;
	while (cin >> S){
		cout << makePalindrome(S, "")<<endl;
	}
}