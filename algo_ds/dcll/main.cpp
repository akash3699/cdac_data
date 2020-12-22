/*
 * main.cpp
 *
 *  Created on: 30-Sep-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>


class list;

class node
{
private:
	int data;
	node *prev;
	node *next;
public:
	node(int data)
	{
		this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}

	friend class list;
};


class list
{
private:
	node *head;
	int cnt;
public:
	list(void)
	{
		this->head = NULL;
		this->cnt = 0;
	}

	bool is_list_empty(void)
	{
		return ( this->head == NULL );
	}

	int get_cnt(void)const
	{
		return ( this->cnt );
	}

	void add_node_at_last_position(int data)
	{
		//create a newnode
		node *newnode = new node(data);

		//if list is empty -- attach newly created node to the head
		if( is_list_empty() )
		{
			head = newnode;
			newnode->next = newnode;
			newnode->prev = head;
			this->cnt++;
		}
		else
		{
			//store the addr of first node into the next part of newly created node
			newnode->next = head;
			//store the addr of cur last node into the prev part of newly created node
			newnode->prev = head->prev;
			//store the addr of newly created node into the next part cur last node
			head->prev->next = newnode;
			//update prev part of first node by newly added node at last pos
			head->prev = newnode;
			this->cnt++;
		}
	}

	void add_node_at_first_position(int data)
	{
		//create a newnode
		node *newnode = new node(data);

		//if list is empty -- attach newly created node to the head
		if( is_list_empty() )
		{
			head = newnode;
			newnode->next = newnode;
			newnode->prev = head;
			this->cnt++;
		}
		else
		{
			//store the addr of cur first node into the next part of newly created node
			newnode->next = head;
			//store the addr of last node into the prev part of newly created node
			newnode->prev = head->prev;
			//store the addr of newly created node into the prev part cur first node
			head->prev = newnode;
			//attach newly created node to the head
			head = newnode;
			//update next part of last node by newly added node at first position
			head->prev->next = head;
			this->cnt++;
		}
	}

	void display_list(void)
	{
		if( !is_list_empty() )
		{
			//start traversal from the first node
			node *trav = head;
			cout << "list in forward dir is : ";
			//traverse the list till last node
			do{
				cout << setw(4) << trav->data;
				trav = trav->next;
			}while( trav != head );
			cout << endl;

			//start traversal from the last node
			trav = head->prev;
			cout << "list in backward dir is: ";
			//traverse the list till first node
			do{
				cout << setw(4) << trav->data;
				trav = trav->prev;
			}while( trav != head->prev );
			cout << endl;

		}
		else
			cout << "list is empty !!!" << endl;
	}

	void delete_node_at_last_position(void)
	{
		//if list is not empty
		if( !is_list_empty())
		{
			//if list contains only one node
			if( head == head->next )
			{
				//delete the node and make head as NULL & cnt as 0
				delete head;
				head = NULL;
				this->cnt = 0;
			}
			else//if list contains more than one nodes
			{
				//store the addr of cur second last node into prev part of
				head->prev = head->prev->prev;
				//delete the last node
				delete head->prev->next;
				//store the addr of first node into the next part of cur second last node
				head->prev->next = head;
				this->cnt--;
			}
		}
		else
			cout << "list is empty !!!" << endl;
	}


	~list(void)
	{
		if( !is_list_empty() )
			free_list();
		else
			cout << "list is empty !!!" << endl;
	}
private:
	void free_list(void)
	{
		while( !is_list_empty())
			delete_node_at_last_position();

		cout << "list freed successfully..." << endl;
	}


};

int main(void)
{

	list l1;

	l1.add_node_at_last_position(10);
	l1.add_node_at_last_position(20);
	l1.add_node_at_last_position(30);
	l1.add_node_at_last_position(40);
	l1.add_node_at_last_position(50);
	l1.add_node_at_last_position(60);

	l1.display_list();

	//l1.add_node_at_first_position(5);

	l1.delete_node_at_last_position();

	l1.display_list();

	return 0;
}




















