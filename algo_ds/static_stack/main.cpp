/*
 * main.cpp
 *
 *  Created on: 01-Oct-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>

#define SIZE 5

class stack
{
private:
	int arr[SIZE];
	int top;
public:
	stack(void)
	{
		this->top = -1;
	}

	bool is_stack_empty(void)
	{
		return ( this->top == -1 );
	}

	bool is_stack_full(void)
	{
		return ( this->top == SIZE-1 );
	}

	void push_element(int ele)
	{
		//- increment the value of top by 1
		this->top++;
		//- insert ele into the stack at top position
		this->arr[ this->top ] = ele;
	}

	void pop_element(void)
	{
		//- decrement the value of top by 1 i.e. we are deleting/popping ele from the stack
		this->top--;
	}

	int peek_element(void)
	{
		//- return/get the value of topmost ele (without incrementing decrementing top).
		return ( this->arr[ this->top ] );
	}

};

enum menu_options{ EXIT, PUSH, POP, PEEK };

int menu(void)
{
	int choice;
	cout << "static stack" << endl;
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
	stack s;

	while(1)
	{
		int choice = menu();
		switch(choice)
		{
		case EXIT: exit(0);

		case PUSH:
			//- check stack is not full
			if( !s.is_stack_full() )
			{
				cout << "enter an ele: ";
				cin >> ele;
				s.push_element(ele);
				cout << ele << " inserted into the stack...." << endl;
			}
			else
				cout << "stack is full !!!" << endl;

			break;
		case POP:
			//- check stack is not empty
			if( !s.is_stack_empty() )
			{
				ele = s.peek_element();
				s.pop_element();
				cout << "popped ele is: " << ele << endl;
			}
			else
				cout << "stack is empty !!!" << endl;

			break;
		case PEEK:
			//- check stack is not empty
			if( !s.is_stack_empty() )
			{
				cout << "topmost ele is: " << s.peek_element() << endl;
			}
			else
				cout << "stack is empty !!!" << endl;

			break;
		}//end of switch control block
	}//end of while loop
	return 0;
}












