
#include <iostream>
#include<string>
using namespace std;


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

	void add_to_first_position(int data)
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
			head->prev=newnode;
			head=newnode;
			head->prev->next=head;
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
private:
	void free_list(void)
	{
		while( !is_list_empty())
			delete_node_at_last_position();

		cout <<endl<<"list freed successfully..." << endl;
	}
public:

	void delete_node_at_first_position(void)
		{

			if( !is_list_empty())
			{

				if( head->next == head )
				{

					delete head;
					head = NULL;
					this->cnt=0;
				}
				else
				{
					/*node *temp=head;
					head->next->prev=head->prev;
					head->prev->next=head->next;
					head = head->next;

					delete temp;
					temp=NULL;
					head->prev = head;
					this->cnt--;*/

					head->next->prev=head->prev;
					head=head->next;
					delete head->prev->next;
					head->prev->next=head;
				}
			}
			else
				cout << "list is empty !!!" << endl;
		}

};//end of list class

int menuChoice(void)
{
	int ch;
	cout<<endl;
	cout<<"0) Exit"<<endl;
	cout<<"1) Enqueue"<<endl;
	cout<<"2) Dequeue"<<endl;
	cout<<"3) Display all"<<endl;
	cout<<" ENter choice"<<endl;
	cin>>ch;
	return ch;
}

int main() {

	list l1;
	int ch=0;
	int data;

	while((ch=menuChoice())!=0)
	{
		switch(ch)
		{
		case 1:
			cout<<"Enter the data";
			cin>>data;
			l1.add_to_last_position(data);
			l1.displayList();
			break;

		case 2:
			l1.delete_node_at_first_position();
			l1.displayList();
			break;

		case 3:
			l1.displayList();
			break;
		default:
			cout<<"Invalid Choice "<<endl;
			break;

		}//end of switch

	}//end of while

	return 0;
}
