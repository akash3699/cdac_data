/*
 * main.cpp
 *
 *  Created on: 01-Oct-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include<queue>

enum menu_options{ EXIT, ENQUEUE, DEQUEUE };

int menu(void)
{
	int choice;
	cout << "dynamic queue" << endl;
	cout << "0. exit" << endl;
	cout << "1. enqueue" << endl;
	cout << "2. dequeue" << endl;
	cout << "enter the choice: ";
	cin >> choice;
	return choice;
}

int main(void)
{
	queue<int> q;
	int ele;

	while(1)
	{
		int choice = menu();
		switch(choice)
		{
		case EXIT: exit(0);
		case ENQUEUE:
			cout << "enter an ele: ";
			cin >> ele;
			q.push(ele);
			cout << ele << " inserted into the queue ..." << endl;
			break;

		case DEQUEUE:
			//- check queue is not empty
			if( !q.empty() )
			{
				ele = q.front();
				q.pop();
				cout << ele << " deleted from the queue ...." << endl;
			}
			else
				cout << "queue is empty !!!" << endl;

			break;
		}//end of switch control block
	}//end of while loop
	return 0;
}








