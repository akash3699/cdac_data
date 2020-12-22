/*
 * main.cpp
 *
 *  Created on: 28-Sep-2019
 *      Author: sunbeam
 */
#include<iostream>
using namespace std;
#include<iomanip>
#include<cstdlib>


class list;

class node
{
private:
	int data;
	node *next;
public:
	node(int data)
	{
		this->data = data;
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

	int get_cnt(void) const
	{
		return ( this->cnt );
	}

	void add_node_at_last_position(int data)
	{
		//create a new node
		node *newnode = new node(data);

		//if list is empty -- attach newly created node to the head
		if( is_list_empty() )
		{
			//store the addr of newly created node into the head
			head = newnode;
			newnode->next = head;
			this->cnt++;
		}
		else
		{
			//start the traversal from first node
			node *trav = head;
			//traverse the list till last node
			while( trav->next != head )
				trav = trav->next;

			//attach newly created node to the last node
			trav->next = newnode;
			//store the addr of first node into the next part newly created node
			newnode->next = head;
			this->cnt++;
		}
	}

	void add_node_at_first_position(int data)
	{
		//create a new node
		node *newnode = new node(data);

		//if list is empty -- attach newly created node to the head
		if( is_list_empty() )
		{
			//store the addr of newly created node into the head
			head = newnode;
			newnode->next = head;
			this->cnt++;
		}
		else
		{
			//start the traversal from first node
			node *trav = head;
			//traverse the list till last node
			while( trav->next != head )
				trav = trav->next;

			//store the addr of cur first node into the next part of newly created node
			newnode->next = head;
			//attach newly created node to the head
			head = newnode;
			//update next part of last node by the head
			trav->next = head;
			this->cnt++;
		}
	}

	void display_list(void)
	{
		if( !is_list_empty())
		{
			//start traversal from first node
			node *trav = head;
			cout << "list is: ";
			do
			{
				cout << setw(4) << left << trav->data;
				trav = trav->next;
			}while( trav != head );
			cout << endl;
		}
		else
			cout << "list is empty !!!" << endl;
	}

	void delete_node_at_first_position(void)
	{
		//if list is not empty
		if( !is_list_empty() )
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
				node *trav = head;
				//traverse the list till last node
				while( trav->next != head )
					trav = trav->next;

				//store the addr of cur second node into the head
				head = head->next;
				//delete the cur first node
				delete trav->next;
				//update next part of last node to the updated first node
				trav->next = head;
				this->cnt--;
			}
		}
		else
			cout << "list is empty !!!" << endl;
	}

	void delete_node_at_last_position(void)
	{
		//if list is not empty
		if( !is_list_empty() )
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
				node *trav = head;
				//traverse the list till second last node
				while( trav->next->next != head )
					trav = trav->next;

				//delete last node
				delete trav->next;
				//update next part of second last node by head
				trav->next = head;
				this->cnt--;
			}
		}
		else
			cout << "list is empty !!!" << endl;
	}

	~list(void)
	{
		if( !is_list_empty())
			free_list();
		else
			cout << "list is empty !!!" << endl;
	}
private:
	void free_list(void)
	{
		while( !is_list_empty() )
			delete_node_at_last_position();

			//delete_node_at_first_position();

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


	l1.display_list();

	l1.delete_node_at_last_position();
	//l1.add_node_at_first_position(5);

	l1.display_list();

	return 0;
}


