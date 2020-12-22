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
#include<stack>
#include<queue>

#define MAX 10

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

		memset(mat, 0, sizeof(mat));
		/*
		for( int i = 0 ; i < MAX ; i++ )
			for( int j = 0 ; j < MAX ; j++ )
				mat[i][j] = 0;
		*/
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
			int from, to;
			cout << "enter an edge: from to to: ";
			cin >> from >> to;

			mat[from][to] = 1;
			mat[to][from] = 1;//for directed graph this line will be in a comment
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
				cout << setw(4) << left << mat[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}

	void dfs_traversal(int start)
	{
		stack<int> s;
		bool marked[MAX];

		//initially all the vertices are unmarked
		for( int v = 0 ; v < vert_cnt ; v++ )
			marked[v] = false;

		//step1: push the starting vertex into the stack and mark it
		s.push(start);
		marked[start] = true;

		cout << "dfs traversal is: ";
		while( !s.empty() )
		{
			//step2: pop the vertex from the stack and visit it
			int trav = s.top(); s.pop();
			cout << setw(4) << left << trav;

			//step3: push all its adjacent but unmarked vertices into the stack and mark them
			for( int v = 0 ; v < vert_cnt ; v++ )
			{
				if( mat[trav][v] != 0 && marked[v] == false )
				{
					s.push(v);
					marked[v] = true;
				}
			}
		}//step4: repeat step2 & step3 till stack not becomes empty.
		cout << endl;
	}

	void dfs_spanning_tree(int root)
	{
		stack<int> s;
		bool marked[MAX];

		//initially all the vertices are unmarked
		for( int v = 0 ; v < vert_cnt ; v++ )
			marked[v] = false;

		//step1: push the root vertex into the stack and mark it
		s.push(root);
		marked[root] = true;

		cout << "dfs spanning tree is: " << endl;
		while( !s.empty() )
		{
			//step2: pop the vertex from the stack
			int trav = s.top(); s.pop();

			//step3: push all its adjacent but unmarked vertices into the stack and mark them
			for( int v = 0 ; v < vert_cnt ; v++ )
			{
				if( mat[trav][v] != 0 && marked[v] == false )
				{
					s.push(v);
					marked[v] = true;
					cout << trav << "->" << v << endl;
				}
			}
		}//step4: repeat step2 & step3 till stack not becomes empty.
		cout << endl;
	}

	void bfs_spanning_tree(int root)
	{
		queue<int> s;
		bool marked[MAX];

		//initially all the vertices are unmarked
		for( int v = 0 ; v < vert_cnt ; v++ )
			marked[v] = false;

		//step1: push the root vertex into the queue and mark it
		s.push(root);
		marked[root] = true;

		cout << "bfs spanning tree is: " << endl;
		while( !s.empty() )
		{
			//step2: pop the vertex from the stack
			int trav = s.front(); s.pop();

			//step3: push all its adjacent but unmarked vertices into the queue and mark them
			for( int v = 0 ; v < vert_cnt ; v++ )
			{
				if( mat[trav][v] != 0 && marked[v] == false )
				{
					s.push(v);
					marked[v] = true;
					cout << trav << "->" << v << endl;
				}
			}
		}//step4: repeat step2 & step3 till queue not becomes empty.
		cout << endl;
	}

	bool is_connected(int source)
	{
		stack<int> s;
		bool marked[MAX];
		int connected_vert_cnt = 0;

		//initially all the vertices are unmarked
		for( int v = 0 ; v < vert_cnt ; v++ )
			marked[v] = false;

		//step1: push the source vertex into the stack and mark it
		s.push(source);
		marked[source] = true;

		while( !s.empty() )
		{
			//step2: pop the vertex from the stack
			int trav = s.top(); s.pop();

			//step3: push all its adjacent but unmarked vertices into the stack and mark them
			for( int v = 0 ; v < vert_cnt ; v++ )
			{
				if( mat[trav][v] != 0 && marked[v] == false )
				{
					s.push(v);
					marked[v] = true;
					connected_vert_cnt++;

					if( connected_vert_cnt == vert_cnt-1 )
						return true;
				}
			}
		}//step4: repeat step2 & step3 till stack not becomes empty.
		cout << endl;

		return ( ( connected_vert_cnt == vert_cnt-1 ) ? true : false );
	}

	void bfs_traversal(int start)
	{
		queue<int> s;
		bool marked[MAX];

		//initially all the vertices are unmarked
		for( int v = 0 ; v < vert_cnt ; v++ )
			marked[v] = false;

		//step1: push the starting vertex into the queue and mark it
		s.push(start);
		marked[start] = true;

		cout << "bfs traversal is: ";
		while( !s.empty() )
		{
			//step2: pop the vertex from the queue and visit it
			int trav = s.front(); s.pop();
			cout << setw(4) << left << trav;

			//step3: push all its adjacent but unmarked vertices into the queue and mark them
			for( int v = 0 ; v < vert_cnt ; v++ )
			{
				if( mat[trav][v] != 0 && marked[v] == false )
				{
					s.push(v);
					marked[v] = true;
				}
			}
		}//step4: repeat step2 & step3 till queue not becomes empty.
		cout << endl;
	}

	void path_length(int source)
	{
		queue<int> s;
		bool marked[MAX];
		int path_len[MAX];

		//initially all the vertices are unmarked & path len of all vertices from
		//source vertex is 0
		for( int v = 0 ; v < vert_cnt ; v++ )
		{
			marked[v] = false;
			path_len[v] = 0;
		}

		//step1: push the source vertex into the queue and mark it
		s.push(source);
		marked[source] = true;

		while( !s.empty() )
		{
			//step2: pop the vertex from the queue and visit it
			int trav = s.front(); s.pop();

			//step3: push all its adjacent but unmarked vertices into the queue
			//mark them & update path length
			for( int v = 0 ; v < vert_cnt ; v++ )
			{
				if( mat[trav][v] != 0 && marked[v] == false )
				{
					s.push(v);
					marked[v] = true;
					path_len[v] = path_len[trav] + 1;
				}
			}
		}//step4: repeat step2 & step3 till queue not becomes empty.
		cout << endl;

		cout << "path length of all vertices from given source vertex is: " << endl;
		for( int v = 0 ; v < vert_cnt ; v++ )
		{
			cout << source << " -> " << v << " : " << path_len[v] << endl;
		}
	}
};

int main(void)
{
	graph g1;

	g1.accept_graph();
	g1.display_graph();

	/*
	int start;
	cout << "enter starting vertex: ";
	cin >> start;
	g1.dfs_traversal(start);
	g1.bfs_traversal(start);


	int source;
	cout << "enter source vertex: ";
	cin >> source;

	if( g1.is_connected(source))
		cout << "g1 is connected ..." << endl;
	else
		cout << "g1 is not connected ..." << endl;


	g1.path_length(source);
	*/

	int root;
	cout << "enter root vertex: ";
	cin >> root;

	g1.dfs_spanning_tree(root);
	g1.bfs_spanning_tree(root);

	return 0;
}








