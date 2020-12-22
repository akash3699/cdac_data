//============================================================================
// Name        : encrypt_string.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class secured
{
private:
	string str;


public:

	secured(void)
	{
		str="sunbeam";

	}
	void encrypt(int key)
	{
		int len = str.length();
		for(int i=0;i<len;i++)
			str[i]=str[i]+key;

	}

	void displayString(void)
	{
		cout<<str;

	}

	void decrypt(int key)
	{
		for(int i=0;i<7;i++)
			str[i]=str[i]-key;

	}
};




int main() {

	secured s1;
	s1.encrypt(4);
	s1.displayString();

	cout<<endl;
	s1.decrypt(4);
	s1.displayString();

	return 0;
}
