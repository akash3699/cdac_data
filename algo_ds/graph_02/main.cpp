/*
 * main.cpp
 *
 *  Created on: 02-Oct-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include<cstring>

#define MAX 10

#define INF 9999

class graph
{
private:
	int mat[MAX][MAX];
	int vert_cnt;
	int edge_cnt;
public:
	graph(void)
	{
		this->vert_cnt = 0;
		this->edge_cnt = 0;

		for( int i = 0 ; i < MAX ; i++ )
			for( int j = 0 ; j < MAX ; j++ )
				mat[i][j] = INF;
	}

	void accept_graph(void)
	{
		cout << "enter the no. of vertices : ";
		cin >> vert_cnt;

		cout << "enter the no. of edges : ";
		cin >> edge_cnt;

		//accept "edge_cnt" no. of pairs from the user
		for( int i = 0 ; i < edge_cnt ; i++ )
		{
			int from, to, weight;
			cout << "enter an edge: from to to & weight : ";
			cin >> from >> to >> weight;

			mat[from][to] = weight;
			mat[to][from] = weight;//for directed graph this line will be in a comment
		}
	}

	void display_graph(void)
	{
		cout << endl << "no. of vertices are: " << vert_cnt << endl;
		cout << "no. of edges are: " << edge_cnt << endl;
		cout << "input graph is: " << endl;

		for( int i = 0 ; i < vert_cnt ; i++ )
		{
			for( int j = 0 ; j < vert_cnt ; j++ )
			{
				if( mat[i][j] != INF )
					cout << setw(4) << left << mat[i][j];
				else
					cout << setw(4) << left << "#";
			}
			cout << endl;
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









