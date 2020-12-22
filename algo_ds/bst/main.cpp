/*
 * main.cpp
 *
 *  Created on: 04-Oct-2019
 *      Author: sunbeam
 */
#include<iostream>
using namespace std;
#include<iomanip>
#include<stack>
#include<queue>

class bst;

class node
{
private:
	int data;
	node *left;
	node *right;
	bool visited;
public:
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->visited = false;
	}

	friend class bst;
};


class bst
{
private:
	node *root;
public:
	bst(void)
	{
		this->root = NULL;
	}

	bool is_bst_empty(void)
	{
		return ( this->root == NULL );
	}

	void add_node(int data)
	{
		//create a  newnode
		node *newnode = new node(data);

		//if bst is empty -- attach newly created node to the root
		if( is_bst_empty())
		{
			root = newnode;
		}
		else
		{
			node *trav = root;

			//find an appropriate position of a node
			while(1)
			{
				if( data < trav->data )//node will be the part of its left subtree
				{
					if( trav->left == NULL )//if left sub tree of the cur node is empty
					{
						trav->left = newnode;//attach newly created node as a left child
						break;
					}
					else
						trav = trav->left;//goto its left  subtree
				}
				else//if( data >= trav->data )//node will be the part of its right subtree
				{
					if( trav->right == NULL )//if the right subtree of cur node is empty
					{
						trav->right = newnode;//attach newly created node as its right child
						break;
					}
					else
						trav = trav->right;//goto its left  subtree
				}
			}//end of while loop
		}//end of else
	}

	void preorder(node *trav)
	{
		if( trav == NULL )
			return;
		//VLR
		cout << setw(4) << left << trav->data;
		preorder(trav->left);
		preorder(trav->right);
	}

	void preorder(void)//wrapper function
	{
		if( !is_bst_empty() )
		{
			cout << "PREORDER : ";
			preorder(root);
			cout << endl;
		}
		else
			cout << "bst is empty !!!" << endl;
	}

	void inorder(node *trav)
	{
		if( trav == NULL )
			return;
		//LVR
		inorder(trav->left);
		cout << setw(4) << left << trav->data;
		inorder(trav->right);
	}

	void inorder(void)//wrapper function
	{
		if( !is_bst_empty() )
		{
			cout << "INORDER  : ";
			inorder(root);
			cout << endl;
		}
		else
			cout << "bst is empty !!!" << endl;
	}

	void postorder(node *trav)
	{
		if( trav == NULL )
			return;
		//LRV
		postorder(trav->left);
		postorder(trav->right);
		cout << setw(4) << left << trav->data;
	}

	void postorder(void)//wrapper function
	{
		if( !is_bst_empty() )
		{
			cout << "POSTORDER: ";
			postorder(root);
			cout << endl;
		}
		else
			cout << "bst is empty !!!" << endl;
	}

	void nonrec_preorder(void)
	{
		node *trav = root;
		stack<node *> s;

		if( trav == NULL )
			return;

		cout << "PREORDER : ";
		while( trav != NULL || !s.empty() )
		{
			while( trav != NULL )
			{
				//visit the node
				cout << setw(4) << left << trav->data;

				//if the cur node is having right child push it into the stack
				if( trav->right != NULL )
					s.push(trav->right);

				//goto its left subtree
				trav = trav->left;
			}

			//if stack is not empty -- pop node from the stack
			if( !s.empty() )
			{
				trav = s.top(); s.pop();
			}
		}
		cout << endl;
	}

	void nonrec_inorder(void)
	{
		node *trav = root;
		stack<node *> s;

		if( trav == NULL )
			return;

		cout << "INORDER  : ";
		while( trav != NULL || !s.empty() )
		{
			while( trav != NULL )
			{
				//push the cur node into the stack
				s.push(trav);

				//goto its left subtree
				trav = trav->left;
			}

			//if stack is not empty -- pop node from the stack
			if( !s.empty() )
			{
				trav = s.top(); s.pop();
				//visit the node
				cout << setw(4) << left << trav->data;
				//goto its right sub tree
				trav = trav->right;
			}
		}
		cout << endl;
	}

	void nonrec_postorder(void)
	{
		node *trav = root;
		stack<node *> s;

		if( trav == NULL )
			return;

		cout << "POSTORDER: ";
		while( trav != NULL || !s.empty() )
		{
			while( trav != NULL )
			{
				//push the cur node into the stack
				s.push(trav);

				//goto its left subtree
				trav = trav->left;
			}

			//if stack is not empty -- pop node from the stack
			if( !s.empty() )
			{
				trav = s.top(); s.pop();
				if( trav->right != NULL && trav->right->visited == false )
				{
					//push the cur node into the stack
					s.push(trav);
					//goto its right sub tree
					trav = trav->right;
				}
				else
				{
					//visit the node and mark it as visited
					cout << setw(4) << left << trav->data;
					trav->visited = true;
					trav = NULL;
				}
			}
		}
		cout << endl;
	}

	~bst(void)
	{
		if( !is_bst_empty())
		{
			free_bst(root);
			cout << "bst freed ...." << endl;
		}
	}

	void dfs_traversal(void)
	{
		if( is_bst_empty())
			return;

		stack<node *> s;
		//step1: push root node into the stack
		s.push(root);
		cout << "DFS TRAVERSAL IS: ";
		while( !s.empty() )
		{
			//step2: pop the node from the stack and visit it
			node *trav = s.top(); s.pop();
			cout << setw(4) << left << trav->data;

			//step3: if the cur node having right child push it into the stack
			if( trav->right != NULL )
				s.push(trav->right);
			//step4: if the cur node having left child push it into the stack
			if( trav->left != NULL )
				s.push(trav->left);
		}//step5: repeat step2, step3 & step4 till stack not becomes empty
		cout << endl;
	}

	void bfs_traversal(void)
	{
		if( is_bst_empty())
			return;

		queue<node *> s;
		//step1: push root node into the queue
		s.push(root);
		cout << "BFS TRAVERSAL IS: ";
		while( !s.empty() )
		{
			//step2: pop the node from the queue and visit it
			node *trav = s.front(); s.pop();
			cout << setw(4) << left << trav->data;

			//step3: if the cur node having left child push it into the queue
			if( trav->left != NULL )
				s.push(trav->left);

			//step4: if the cur node having right child push it into the queue
			if( trav->right != NULL )
				s.push(trav->right);

		}//step5: repeat step2, step3 & step4 till queue not becomes empty
		cout << endl;
	}

	node *search_node(int key, node **parent)
	{
		node *trav = root;

		*parent = NULL;

		while( trav != NULL )
		{
			if( key == trav->data )
				return trav;

			*parent = trav;
			if( key < trav->data )
				trav = trav->left;
			else
				trav = trav->right;
		}

		*parent = NULL;
		return NULL;
	}

	bool delete_node(int key)
	{
		node *parent = NULL;
		node *temp = search_node(key, &parent);

		if( temp == NULL )
			return false;

		if( temp->left != NULL && temp->right != NULL )
		{
			parent = temp;
			node *succ = temp->right;

			while( succ->left != NULL )
			{
				parent = succ;
				succ = succ->left;
			}

			temp->data = succ->data;
			temp = succ;
		}

		if( temp->right != NULL )
		{
			if( temp == root )
				root = temp->right;
			else
			if( temp == parent->right )
				parent->right = temp->right;
			else
				parent->left = temp->right;
		}
		else
		{
			if( temp == root )
				root = temp->left;
			else
			if( temp == parent->left )
				parent->left = temp->left;
			else
				parent->right = temp->left;
		}

		delete temp;

		return true;
	}

	int height(node *trav)
	{
		if( trav == 0 )
			return 0;
		return ( max( height(trav->left), height(trav->right) ) + 1 );
	}

	int height(void)
	{
		if( !is_bst_empty() )
			return height(root);
	}

	node *left_rotation(node *axis, node *parent)
	{
		if( axis == NULL || axis->right == NULL )
			return NULL;

		node *newaxis = axis->right;
		axis->right = newaxis->left;
		newaxis->left = axis;

		if( axis == root )
			root = newaxis;
		else
		if( axis == parent->left )
			parent->left = newaxis;
		else
			parent->right = newaxis;

		return newaxis;
	}

	node *right_rotation(node *axis, node *parent)
	{
		if( axis == NULL || axis->left == NULL )
			return NULL;

		node *newaxis = axis->left;
		axis->left = newaxis->right;
		newaxis->right = axis;

		if( axis == root )
			root = newaxis;
		else
		if( axis == parent->left )
			parent->left = newaxis;
		else
			parent->right = newaxis;

		return newaxis;
	}

	void balance(node *trav, node *parent)
	{
		if( trav == NULL )
			return;

		int bf = height(trav->left) - height(trav->right);

		while( bf <= -1 || bf >= +1 )
		{
			if( bf <= -1 )//node is left imbalanced
			{
				trav = left_rotation(trav, parent);
				bf += 2;
			}
			else//node is right imbalanced
			{
				trav = right_rotation(trav, parent);
				bf -= 2;
			}
		}

		balance(trav->left, trav);
		balance(trav->right, trav);
	}

	void balance(void)
	{
		if( !is_bst_empty())
			balance(root, NULL);
	}

private:
	void free_bst(node *trav)
	{
		if( trav == NULL )
			return;
		free_bst(trav->left);
		free_bst(trav->right);
		delete trav;
	}
};

int main(void)
{
	bst t1;
	/*
	//50 20 90 85 10 45 30 100 15 75 95 120 5 50
	t1.add_node(50);
	t1.add_node(20);
	t1.add_node(90);
	t1.add_node(85);
	t1.add_node(10);
	t1.add_node(45);
	t1.add_node(30);
	t1.add_node(100);
	t1.add_node(15);
	t1.add_node(75);
	t1.add_node(95);
	t1.add_node(120);
	t1.add_node(5);
	t1.add_node(50);
	*/
	t1.add_node(10); t1.add_node(20); t1.add_node(30); t1.add_node(40);
	t1.add_node(50); t1.add_node(60); t1.add_node(70);

	t1.preorder();
	//t1.nonrec_preorder();

	t1.inorder();
	//t1.nonrec_inorder();

	t1.postorder();
	//t1.nonrec_postorder();

	t1.dfs_traversal();
	t1.bfs_traversal();
	/*
	int key;
	cout << "enter the key/data of a node to be deleted : ";
	cin >> key;

	if( t1.delete_node(key) )
		cout << key << " is deleted from the bst" << endl;
	else
		cout << key << " is not found in a bst" << endl;

	t1.preorder();
	t1.inorder();
	t1.postorder();
	t1.dfs_traversal();
	t1.bfs_traversal();
	*/

	cout << "height of a tree t1 : " << t1.height() << endl;
	t1.balance();

	cout << "height of a tree t1 : " << t1.height() << endl;
	t1.dfs_traversal();
	t1.bfs_traversal();


	return 0;
}
