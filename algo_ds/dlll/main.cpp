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
		if( is_list_empty())
		{
			//store the addr of newly created node into the head
			head = newnode;
			this->cnt++;
		}
		else//if list is not empty
		{
			node *trav = head;
			//traverse list last node
			while( trav->next != NULL )
				trav = trav->next;

			//store the addr of cur last node into the prev of newly created node
			newnode->prev = trav;
			//store the addr of newly created node into the next part of cur last node
			trav->next = newnode;
			this->cnt++;
		}
	}

	void add_node_at_first_position(int data)
	{
		//create a newnode
		node *newnode = new node(data);

		//if list is empty -- attach newly created node to the head
		if( is_list_empty())
		{
			//store the addr of newly created node into the head
			head = newnode;
			this->cnt++;
		}
		else//if list is not empty
		{
			//store the add of cur first node into the prev part of newly created node
			newnode->next = head;
			//store the addr of newly created node into the prev of part of cur first node
			head->prev = newnode;
			//attach newly created node to the head
			head = newnode;
			this->cnt++;
		}
	}

	void display_list(void)
	{
		if( !is_list_empty())
		{
			//start traversal from first node
			node *trav = head;
			node *temp = NULL;
			cout << "no. of nodes are: " << get_cnt() << endl;
			cout << "list in a forward dir is : ";
			//traverse the list till last node
			while( trav != NULL )
			{
				temp = trav;
				cout << setw(4) << left << trav->data;
				trav = trav->next;
			}
			cout << endl;
			//start traversal from the last node
			trav = temp;
			cout << "list in a backward dir is: ";
			//traverse the list till first node
			while( trav != NULL )
			{
				cout << setw(4) << left << trav->data;
				trav = trav->prev;
			}
			cout << endl;

		}
		else
			cout << "list is empty !!!" << endl;
	}

	void add_node_at_specific_position(int data, int pos)
	{
		if( pos == 1 )//if pos is the first position
			add_node_at_first_position(data);
		else
		if( pos == get_cnt() + 1 )//if position is the last position
			add_node_at_last_position(data);
		else//if pos is in between position
		{
			//create a newnode
			node *newnode = new node(data);

			node *trav = head;
			int i=1;
			//traverse the list till (pos-1)th node
			while( i < pos-1 )
			{
				i++;
				trav = trav->next;
			}

			//store the add of cur (pos)th node into the next part of newly created node
			newnode->next = trav->next;
			//store the add of (pos-1)th node into the prev part of newly created node
			newnode->prev = trav;
			//store the addr of newly created node into the prev part of cur (pos)th node
			trav->next->prev = newnode;
			//store the addr of newly created node into the next part of (pos-1)th node
			trav->next = newnode;
			this->cnt++;
		}
	}

	void delete_node_at_first_position(void)
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
				//store the cur second node into the head
				head = head->next;
				//delete the first node
				delete head->prev;
				//make prev part of modified first node as NULL
				head->prev = NULL;
				this->cnt--;
			}
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
				//make next part of second last node as NULL
				trav->next = NULL;

				this->cnt--;
			}
		}
		else
			cout << "list is empty !!!" << endl;
	}

	void delete_node_at_specific_position(int pos)
	{
		if( pos == 1 )//if the pos is the first position
			delete_node_at_first_position();
		else
		if( pos == get_cnt() )//if the pos is the last position
			delete_node_at_last_position();
		else//if the pos is in between position
		{
			node *trav = head;
			int i = 1;
			//traverse the list till (pos-1)th node
			while( i < pos-1 )
			{
				i++;
				trav = trav->next;
			}

			//store the addr of (pos+1)th node into the next part of (pos-1)th node
			trav->next = trav->next->next;
			//delete the node
			delete trav->next->prev;
			//store the addr of (pos-1)th node into the prev part of (pos+1)th node
			trav->next->prev = trav;
			this->cnt--;
		}
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
	l1.add_node_at_last_position(60);

	l1.display_list();

	//l1.add_node_at_first_position(5);


	int pos;
	while(1)
	{
		cout << "enter pos: ";
		cin >> pos;
		if( pos >= 1 && pos <= l1.get_cnt() )
			break;

		cout << "invalid position ..." << endl;
	}

	l1.delete_node_at_specific_position(pos);

	//l1.add_node_at_specific_position(99, pos);

	//l1.delete_node_at_first_position();
	//l1.delete_node_at_last_position();
	l1.display_list();

	return 0;
}
















