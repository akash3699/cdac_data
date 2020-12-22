/*
 * list.h
 *
 *  Created on: 27-Sep-2019
 *      Author: sunbeam
 */

#ifndef LIST_H_
#define LIST_H_

#include"node.h"

class list
{
private:
	node *head;
	int cnt;
public:
	list(void);
	bool is_list_empty(void);
	int get_cnt(void)const;
	void add_node_at_last_position(int data);
	void add_node_at_first_position(int data);
	void add_node_at_specific_position(int data, int pos);
	void delete_node_at_first_position(void);
	void delete_node_at_last_position(void);
	void delete_node_at_specific_position(int pos);
	void display_reverse(node *trav);
	void display_reverse(void);
	void reverse_list(void);
	int count_nodes(void);
	void display_list(void);
	~list(void);
private:
	void free_list(void);
};



#endif /* LIST_H_ */
