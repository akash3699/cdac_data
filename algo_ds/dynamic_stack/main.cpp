/*
 * main.cpp
 *
 *  Created on: 01-Oct-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include<stack>

enum menu_options{ EXIT, PUSH, POP, PEEK };

int menu(void)
{
	int choice;
	cout << "dynamic stack" << endl;
	cout << "0. exit" << endl;
	cout << "1. push" << endl;
	cout << "2. pop" << endl;
	cout << "3. peek" << endl;
	cout << "enter the choice: ";
	cin >> choice;

	return choice;
}

int main(void)
{
	int ele;
	stack<int> s;

	while(1)
	{
		int choice = menu();
		switch(choice)
		{
		case EXIT: exit(0);

		case PUSH:
			cout << "enter an ele: ";
			cin >> ele;
			s.push(ele);
			cout << ele << " inserted into the stack...." << endl;
			break;

		case POP:
			//- check stack is not empty
			if( !s.empty() )
			{
				ele = s.top();
				s.pop();
				cout << "popped ele is: " << ele << endl;
			}
			else
				cout << "stack is empty !!!" << endl;

			break;
		case PEEK:
			//- check stack is not empty
			if( !s.empty() )
			{
				cout << "topmost ele is: " << s.top() << endl;
			}
			else
				cout << "stack is empty !!!" << endl;

			break;
		}//end of switch control block
	}//end of while loop
	return 0;
}
















