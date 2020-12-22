/*
 * node.h
 *
 *  Created on: 27-Sep-2019
 *      Author: sunbeam
 */

#ifndef NODE_H_
#define NODE_H_

//forward declaration
class list;

class node
{
private:
	int data;
	node *next;//self referential pointer
public:
	node(int data);
	//getter functions -- inspectors
	//setter functions -- mutators
	//facilitators
	//dtor

	friend class list;
};



#endif /* NODE_H_ */
