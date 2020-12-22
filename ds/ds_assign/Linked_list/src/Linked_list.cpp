#include <iostream>
using namespace std;


class node
{
private:
	int data;
	node * next;

public:

	node(void)
	{
		this->data=0;
		this->next=NULL;
	}

	node(int data)
	{
		this->data=data;
		this->next=NULL;
	}
	friend class list;
};


class list
{
private:
	node *head=NULL;

public:

	list(void){
		this->head=NULL;
	}

	bool isempty(void)
	{
		return (this->head==NULL);
	}

	void add_node_last(int data)
	{
		node *nextnode=new node(data);
		if(isempty())
		{
			head=nextnode;

		}
		else
		{
			node *trav=head;
			while(trav->next!=NULL)
			{
				trav=trav->next;
			}
			trav->next=nextnode;
		}


	}

	void traverselist(void)
	{
		if(isempty())
		{
			cout<<"EMpty list"<<endl;

		}
		else
		{
			while(head!=NULL)
			{
				cout<<head->data<<" --> ";
				head=head->next;
			}
		}

	}
};


int main() {

	list l1;
	l1.add_node_last(100);
	l1.add_node_last(110);
	l1.add_node_last(120);
	l1.add_node_last(130);
	l1.add_node_last(140);
	l1.traverselist();

	return 0;
}
