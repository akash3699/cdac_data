/*
 * list.cpp
 *
 *  Created on: 27-Sep-2019
 *      Author: sunbeam
 */


#include"list.h"
using namespace std;





list::list(void){
	this->head=NULL;
}

bool list::isempty(void)
{
	return (this->head==NULL);
}

void list::add_node_last(int data)
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

void list::traverselist(void)
{
	if(isempty())
	{
		cout<<"EMpty list"<<endl;

	}
	else
	{
		node *trav=head;
		while(trav!=NULL)
		{
			cout<<trav->data<<" --> ";
			trav=trav->next;
		}
	}

}

void list::deleteLast(void)
{

	if(isempty())
	{
		cout<<"EMpty list"<<endl;

	}
	else
	{
		node *trav = head;
		while(trav->next->next!=NULL)
		{
			//cout<<trav->data<<" --> ";
			trav=trav->next;
		}

		delete trav->next;
		trav->next=NULL;

	}


}

void list::deleteFirst(void)
	{

		if(isempty())
		{
			cout<<"EMpty list"<<endl;

		}
		else
		{
			node *trav = head->next;
			//node temp = head->next;

			delete head;
			head=trav;
			//trav->next=NULL;

		}


	}


int menuChoice(void)
{
	int ch;
	cout<<endl;
	cout<<"0) Exit"<<endl;
	cout<<"1) Insert"<<endl;
	cout<<"2) Delete Last"<<endl;
	cout<<"3) Delete First"<<endl;
	cout<<"4) Display Linked List"<<endl;
	cout<<" ENter choice"<<endl;
	cin>>ch;
	return ch;
}


