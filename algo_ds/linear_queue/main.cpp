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

class queue
{
private:
	int arr[SIZE];
	int front;
	int rear;
public:
	queue(void)
	{
		this->rear = -1;
		this->front = -1;
	}

	bool is_queue_full(void)
	{
		return ( this->rear == SIZE-1 );
	}

	bool is_queue_empty(void)
	{
		return ( this->rear == -1 || this->front > this->rear );
	}

	void enqueue(int ele)
	{
		//- increment the value of rear by 1
		this->rear++;
		//- push ele into the queue at rear position
		this->arr[ this->rear ] = ele;
		//- if( front == -1 ) --> front = 0
		if( this->front == -1 )
			this->front = 0;
	}

	void dequeue(void)
	{
		//- increment the value of front by 1 [ i.e. we are deleting ele from the queue].
		this->front++;
	}

	int get_front(void)
	{
		//return the value of ele which is at front position (without addition/deletion)
		return ( this->arr[ this->front ] );
	}

};

enum menu_options{ EXIT, ENQUEUE, DEQUEUE };

int menu(void)
{
	int choice;
	cout << "linear queue" << endl;
	cout << "0. exit" << endl;
	cout << "1. enqueue" << endl;
	cout << "2. dequeue" << endl;
	cout << "enter the choice: ";
	cin >> choice;
	return choice;
}

int main(void)
{
	queue q;
	int ele;

	while(1)
	{
		int choice = menu();
		switch(choice)
		{
		case EXIT: exit(0);
		case ENQUEUE:
			//- check queue is not full
			if( !q.is_queue_full() )
			{
				cout << "enter an ele: ";
				cin >> ele;
				q.enqueue(ele);
				cout << ele << " inserted into the queue ..." << endl;
			}
			else
				cout << "queue is full !!!" << endl;

			break;
		case DEQUEUE:
			//- check queue is not empty
			if( !q.is_queue_empty() )
			{
				ele = q.get_front();
				q.dequeue();
				cout << ele << " deleted from the queue ...." << endl;
			}
			else
				cout << "queue is empty !!!" << endl;

			break;
		}//end of switch control block
	}//end of while loop
	return 0;
}

