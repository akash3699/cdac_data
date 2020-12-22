
#include <iostream>
#include<string>
using namespace std;
class emp
{
private:
	int empid;
	string name;
	float salary;

public:
	emp(void)
	{
		this->empid=0;
		this->name="";
		this->salary=0.0;
	}

	emp(emp &other)
	{
		this->empid=other.empid;
		this->name=other.name;
		this->salary=other.salary;
	}
	friend ostream &operator<<(ostream &cout,const emp &e1);
	friend istream &operator>>(istream &cin,emp &e1);

};//end of emp class

istream &operator>>(istream &cin,emp &e1)
{
	cout<<"\nEnter EMP ID ";
	cin>>e1.empid;
	cout<<"\nEnter EMP Name ";
	cin>>e1.name;
	cout<<"\nEnter EMP Salary ";
	cin>>e1.salary;
return cin;

}

ostream &operator<<(ostream &cout,const emp &e1)
{
	cout<<e1.empid<<"	";
	cout<<e1.name<<"	";
	cout<<e1.salary<<"	";
return cout;

}
class node
{
private:
	emp data;
	node *prev=NULL;
	node *next=NULL;

public:

	node(void)
	{
		//this->data=NULL;
		this->next=NULL;
		this->prev=NULL;
	}

	node(int data)
	{
		//this->data=data;
		this->next=NULL;
		this->prev=NULL;
	}

	node(emp &data)
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
		}
	}

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

	void displayList()
	{
		node *trav=head;
		cout<<endl<<"Emp Details :: "<<endl<<"EMPID EMP_Name EMP_Salary"<<endl;
		if(!is_list_empty())
		{
			do
			{
				cout<<trav->data<<" -> "<<endl;
				trav=trav->next;
			}while(trav!=head);

			/*cout<<endl<<"Backward Direction    ";
			trav=head->prev;
			do
			{
				cout<<trav->data<<" -> ";
				trav=trav->prev;
			}while(trav!=head->prev);*/

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
	void add_to_last_position(emp data)
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

			}

		}

};//end of list class

int menuChoice(void)
{
	int ch;
	cout<<endl;
	cout<<"0) Exit"<<endl;
	cout<<"1) Insert EMP"<<endl;
	cout<<"2) Delete Last EMP"<<endl;
	cout<<"3) Display all EMP"<<endl;
	cout<<" ENter choice"<<endl;
	cin>>ch;
	return ch;
}

int main() {

	list l1;
	emp e1;
	int ch=0;

	while((ch=menuChoice())!=0)
	{
		switch(ch)
		{
		case 1:
			cin>>e1;
			l1.add_to_last_position(e1);
			l1.displayList();
			break;

		case 2:
			l1.delete_node_at_last_position();
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


	/*cin>>e1;
	l1.add_to_last_position(e1);
	l1.displayList();
	l1.delete_node_at_last_position();
	l1.displayList();*/
	return 0;
}
