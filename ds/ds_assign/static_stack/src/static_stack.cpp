
#include <iostream>
using namespace std;

#define SIZE 5

class stack
{
private:
	int arr[SIZE];
	int top;

public:

	stack(void)
	{
		this->top=-1;
	}

	bool is_full()
	{
		return (this->top==SIZE-1);
	}

	bool is_empty()
	{
		return (this->top==-1);
	}

	void push(int data)
	{
		this->arr[++this->top]=data;
	}

	void pop(void)
	{
		this->top--;

	}

	int peek(void)
	{
		return this->arr[this->top];
	}
};

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


int main() {

	stack s;
	int ch,data;

	while((ch=menu())!=0)
	{
		switch(ch)
		{
		case 1:

			if( !s.is_full() )
			{
				cout << "enter an ele: ";
				cin >>data;
				s.push(data);
				cout << data << " inserted into the stack...." << endl;
			}
			else
				cout << "stack is full !!!" << endl;

			break;
		case 2:

			if( !s.is_empty() )
			{
				data = s.peek();
				s.pop();
				cout << "popped ele is: " << data << endl;
			}
			else
				cout << "stack is empty !!!" << endl;

			break;
		case 3:
			//- check stack is not empty
			if( !s.is_empty() )
			{
				cout << "topmost ele is: " << s.peek() << endl;
			}
			else
				cout << "stack is empty !!!" << endl;

			break;
		}//end of switch control block





	}
	/*s.push(10);
	s.push(20);
	cout<<s.peek();
	s.pop();
	cout<<s.peek();*/
	return 0;
}
