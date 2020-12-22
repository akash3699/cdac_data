/*
 * list.cpp
 *
 *  Created on: 27-Sep-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include"list.h"
#include<cstdlib>


list::list(void)
{
	this->head = NULL;
	this->cnt=0;
}

bool list::is_list_empty(void)
{
	return ( this->head == NULL );
}

int list::get_cnt(void)const
{
	return ( this->cnt );
}

void list::add_node_at_last_position(int data)
{
	//create a newnode - allocate memory dynamically for node & initialize its members
	node *newnode = new node(data);

	//if list is empty -- then attach newly created node to the head
	if( is_list_empty() )
	{
		//store the addr of newly created node into the head
		head = newnode;
		this->cnt++;
	}
	else//if list is not empty
	{
		//start traversal of list from first node
		node *trav = head;

		//traverse the list till last node
		while( trav->next != NULL )
			trav = trav->next;//move trav pointer to its next node

		//attach newly created node to the last node
		//i.e. store the addr of newly created node into the next part of last node
		trav->next =  newnode;
		this->cnt++;
	}
}

void list::add_node_at_first_position(int data)
{
	//create a newnode - allocate memory dynamically for node & initialize its members
	node *newnode = new node(data);

	//if list is empty -- then attach newly created node to the head
	if( is_list_empty() )
	{
		//store the addr of newly created node into the head
		head = newnode;
		this->cnt++;
	}
	else//if list is not empty
	{
		//store the addr cur first node into the next part of newly created node
		newnode->next = head;
		//attach newly created node to the head i.e. store the addr of newly
		//created node into the head
		head = newnode;
		this->cnt++;
	}
}


void list::add_node_at_specific_position(int data, int pos)
{
	if( pos == 1 )//pos is the first pos
		add_node_at_first_position(data);
	else
	if( pos == get_cnt() + 1 )//pos is the last position
		add_node_at_last_position(data);
	else//pos is in between position
	{
		//create a newnode
		node *newnode = new node(data);
		//start traversal from the first node
		node *trav = head;
		int i = 1;

		//traverse list till (pos-1)th node
		while( i < pos-1 )
		{
			i++;
			trav = trav->next;
		}

		//store the addr of cur (pos)th node into the next part of newly created node
		newnode->next = trav->next;
		//store the addr of newly created node into the next part of (pos-1)th node
		trav->next = newnode;
		this->cnt++;
	}
}

void list::delete_node_at_first_position(void)
{
	//if list is not empty
	if( !is_list_empty())
	{
		//if list contains only one node
		if( head->next == NULL )
		{
			//delete the node and make head as NULL & cnt as 0
			delete head;
			head = NULL;
			this->cnt=0;
		}
		else//if list contains more than one nodes
		{
			//store the addr of first node into a temp
			node *temp = head;
			//store the addr of cur second node into the head
			head = head->next;
			//delete the node
			delete temp;
			temp = NULL;
			this->cnt--;
		}
	}
	else
		cout << "list is empty !!!" << endl;
}

void list::delete_node_at_last_position(void)
{
	//if list is not empty
	if( !is_list_empty())
	{
		//if list contains only one node
		if( head->next == NULL )
		{
			//delete the node and make head as NULL & cnt as 0
			delete head;
			head = NULL;
			this->cnt=0;
		}
		else//if list contains more than one nodes
		{
			//start traversal from first node
			node *trav = head;

			//traverse the list till second last node
			while( trav->next->next != NULL )
				trav = trav->next;

			//delete the last node
			delete trav->next;
			//make next part second last node as NULL
			trav->next = NULL;
			this->cnt--;
		}
	}
	else
		cout << "list is empty !!!" << endl;
}

int list::count_nodes(void)
{
	int cnt = 0;
	node *trav = head;
	while( trav != NULL )
	{
		cnt++;
		trav = trav->next;
	}
	return cnt;
}

void list::display_list(void)
{
	if( !is_list_empty())
	{
		//start traversal from first node
		node *trav = head;
		//cout << "no. of nodes in a list are: " << count_nodes() << endl;
		cout << "no. of nodes in a list are: " << get_cnt() << endl;
		cout << "list is: head -> ";

		//traverse the list last node including last node
		while( trav != NULL )
		{
			cout << trav->data << " -> ";//display data part of the node
			trav = trav->next;//move trav pointer to its next node
		}
		cout << "null" << endl;
	}
	else
		cout << "list is empty !!!" << endl;
}

void list::delete_node_at_specific_position(int pos)
{
	if( pos == 1 )//if pos is the first position
		delete_node_at_first_position();
	else
	if ( pos == get_cnt() )//if pos is the last position
		delete_node_at_last_position();
	else//if the pos is in between position
	{
		//start traversal from the first node
		node *trav = head;
		int i = 1;
		//traverse the list till (pos-1)th node
		while( i < pos-1 )
		{
			i++;
			trav = trav->next;
		}

		//store the addr of node to be deleted in a temp pointer
		node *temp = trav->next;
		//store the addr of cur (pos+1)th node into the next part (pos-1)th node
		trav->next = trav->next->next;
		//delete the node
		delete temp;
		temp = NULL;
		this->cnt--;
	}
}

void list::display_reverse(void)//wrapper function
{
	if( !is_list_empty())
	{
		cout << "list is reverse order is: ";
		display_reverse(this->head);
		cout << endl;
	}
	else
		cout << "list is empty !!!" << endl;
}

void list::display_reverse(node *trav)
{
	if( trav == NULL )
		return;

	display_reverse(trav->next);
	cout << setw(4) << left << trav->data;
}

list::~list(void)
{
	if( !is_list_empty())
		 free_list();
	else
		cout << "list is empty !!!" << endl;
}

void list::free_list(void)
{
	while( !is_list_empty() )
		delete_node_at_last_position();
		//delete_node_at_first_position();

	cout << "list freed successfully... " << endl;
}

void list::reverse_list(void)
{
	if( !is_list_empty())
	{
		node *t1 = head;
		node *t2 = t1->next;
		t1->next = NULL;//make next part of cur first node as NULL

		while( t2 != NULL )
		{
			node *t3 = t2->next;//store the addr of next node of t2 into t3
			t2->next = t1;//reverse the link of pair of nodes -- t2 & t1
			t1 = t2;//move t1 to its next node
			t2 = t3;//move t2 to its next node
		}
		//store the addr of cur last node into the head
		head = t1;
	}
	else
		cout << "list is empty !!!" << endl;
}
