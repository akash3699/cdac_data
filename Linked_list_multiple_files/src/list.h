/*
 * list.h
 *
 *  Created on: 27-Sep-2019
 *      Author: sunbeam
 */

#ifndef LIST_H_
#define LIST_H_
#include<iostream>
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

	list(void);
	bool isempty(void);
	void add_node_last(int data);
	void traverselist(void);
	void deleteLast(void);
	void deleteFirst(void);
};




#endif /* LIST_H_ */
