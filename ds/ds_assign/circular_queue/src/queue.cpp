//Circular queue
#include <iostream>
using namespace std;

#define SIZE 5
class queue
{
private:
	int arr[SIZE];
	int front;
	int rare;

public:
	queue(void)
	{

		this->front=-1;
		this->rare=-1;
	}

	bool is_empty(void)
	{
		return (this->rare==-1 || this->front == this->rare);
	}

	bool is_full(void)
	{
		return (this->front==(this->rare+1)%SIZE);
	}

	void enqueue(int data)
	{
		this->rare=(this->rare+1)%SIZE;
		this->arr[this->rare]=data;
		if(this->front==-1)
			this->front=0;
	}

	void dequeue(void)
	{
		if(this->front==this->rare)
			this->front=this->rare=-1;
		else
			this->front=(this->front+1)%SIZE;
	}

	int getFront()
	{
		return (this->arr[this->front]);
	}
};


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

int main() {

	queue q;
	int data,choice;
	while((choice=menu())!=0)
	{
		switch(choice)
		{

		case 1:

			if( !q.is_full() )
			{
				cout << "enter an ele: ";
				cin >> data;
				q.enqueue(data);
				cout << data << " inserted into the queue ..." << endl;
			}
			else
				cout << "queue is full !!!" << endl;

			break;
		case 2:

			if( !q.is_empty() )
			{
				data = q.getFront();
				q.dequeue();
				cout << data << " deleted from the queue ...." << endl;
			}
			else
				cout << "queue is empty !!!" << endl;

			break;
		}//end of switch control block
	}//end of while loop

	return 0;
}
