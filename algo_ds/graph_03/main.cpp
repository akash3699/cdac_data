/*
 * main.cpp
 *
 *  Created on: 02-Oct-2019
 *      Author: sunbeam
 */
#include<iostream>
using namespace std;
#include<iomanip>
#include<vector>
#include<list>
#include<iterator>

class graph
{
private:
	vector<list<int>> gr;
	int vert_cnt;
	int edge_cnt;
public:
	graph(void)
	{
		this->vert_cnt = 0;
		this->edge_cnt = 0;
	}

	void accept_graph(void)
	{
		cout << "enter no. of vertices: ";
		cin >> vert_cnt;

		cout << "enter no. of edges: ";
		cin >> edge_cnt;

		//add "vert_cnt" no. of empty lists into the vector
		for( int i = 0 ; i < vert_cnt ; i++ )
		{
			list<int> empty_list;
			gr.push_back(empty_list);
		}

		for( int i = 0 ; i < edge_cnt ; i++ )
		{
			int from, to;
			cout << "enter an edge: from to to: ";
			cin >> from >> to;

			gr[from].push_back(to);
			gr[to].push_back(from);//for di-graph this line will be in comment

		}
	}

	void display_graph(void)
	{
		cout << endl << "no. of vertices are : " << vert_cnt << endl;
		cout << "no. of edges are: " << edge_cnt << endl;
		cout << "input graph is : " << endl;

		list<int>::iterator itr;

		//traversal of a vector
		for( int index = 0 ; index < vert_cnt ; index++ )
		{
			cout << "[ " << index << " ] " << " => ";
			//traversal of a list
			for( itr = gr[index].begin() ; itr != gr[index].end() ; itr++ )
				cout << *itr << " -> ";
			cout << "null" << endl;
		}
		cout << endl;
	}
};

int main(void)
{
	graph g1;

	g1.accept_graph();
	g1.display_graph();

	return 0;
}




