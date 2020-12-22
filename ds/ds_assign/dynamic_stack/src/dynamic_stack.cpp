
#include <iostream>
using namespace std;

#define SIZE 5

class node
{
private:
	int data;
	node *prev=NULL;
	node *next=NULL;

public:

	node(void)
	{
		this->data=0;
		this->next=NULL;
		this->prev=NULL;
	}

	node(int data)
	{
		this->data=data;
		this->next=NULL;
		this->prev=NULL;
	}


	friend class list;

}; //end of node class


class list
{
private:
	int cnt;
	node *head= NULL;

public:

	list(void)
	{
		this->cnt=0;
		this->head=NULL;
	}

	bool is_list_empty(void)
	{
		return ( this->head == NULL );
	}

	int get_cnt(void)const
	{
		return ( this->cnt );
	}

	void add_to_last_position(int data)
	{
		node *newnode=new node(data);
		if(is_list_empty())
		{
			head=newnode;
			newnode->next=newnode;
			newnode->prev=head;
			this->cnt++;
		}
		else
		{
			newnode->next=head;
			newnode->prev=head->prev;
			head->prev->next=newnode;
			head->prev=newnode;
			this->cnt++;
		}
	}


	void displayList()
	{
		node *trav=head;

		if(!is_list_empty())
		{
			do
			{
				cout<<trav->data<<" -> ";
				trav=trav->next;
			}while(trav!=head);


		}
		else
			cout<<"List is empty"<<endl;

	}

	void delete_node_at_last_position()
	{
		if(!is_list_empty())
		{
			if(head==head->next)
			{
				delete head;
				head=NULL;
				this->cnt=0;
			}
			else
			{
				head->prev=head->prev->prev;
				delete head->prev->next;
				head->prev->next=head;
				this->cnt--;
			}
		}
		else
		{
			cout<<" List is empty"<<endl;
		}
	}


	~list(void)
		{
			if( !is_list_empty() )
				free_list();
			else
				cout<<endl<< "list is empty !!!" << endl;
		}
	void peek()
		{
			node *trav=head;

			if(!is_list_empty())
			{
				int i=1;
				do
				{
					if(i==cnt)
					{
						cout<<trav->data<<" -> ";
					}
					i++;
					trav=trav->next;
				}while(trav!=head);


			}
			else
				cout<<"List is empty"<<endl;

		}


private:
	void free_list(void)
	{
		while( !is_list_empty())
			delete_node_at_last_position();

		cout <<endl<<"list freed successfully..." << endl;
	}
};//end of list class



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

	list s;
	int ch,data;

	while((ch=menu())!=0)
	{
		switch(ch)
		{
		case 1:
				cout << "enter an ele: ";
				cin >>data;
				s.add_to_last_position(data);
				cout << data << " inserted into the stack...." << endl;
			break;
		case 2:

			if( !s.is_list_empty() )
			{
				cout << "popped ele is: ";
				s.peek();
				cout<< endl;
				s.delete_node_at_last_position();

			}
			else
				cout << "stack is empty !!!" << endl;

			break;
		case 3:

			if( !s.is_list_empty() )
			{
				cout << "topmost ele is: ";
				s.peek();
				cout<< endl;
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
