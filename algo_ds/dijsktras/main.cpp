/*
 * main.cpp
 *
 *  Created on: 03-Oct-2019
 *      Author: sunbeam
 */

//dijsktra's algo - to find shortest distance of all vertices from the given source
//vertex:

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
	int weight_of_graph;
public:
	graph(void)
	{
		this->vert_cnt = 0;
		this->edge_cnt = 0;
		this->weight_of_graph=0;

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
			this->weight_of_graph += weight;
		}
	}

	void display_graph(void)
	{
		cout << endl << "no. of vertices are: " << vert_cnt << endl;
		cout << "no. of edges are: " << edge_cnt << endl;
		cout << "weight of the graph is: " << weight_of_graph << endl;
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

	int get_min(int dist[], bool mst_set_vert[])
	{
		int min_ind = 0;
		int min_dist = INF;

		for( int i = 0 ; i < vert_cnt ; i++ )
		{
			if( mst_set_vert[i] == false && dist[i] < min_dist )
			{
				min_ind = i;
				min_dist = dist[i];
			}
		}

		/* this function returns such vertex which is not yet added into MST set
		   of vertices and having min key value */
		return min_ind;
	}

	void dijsktras(int source)
	{
		bool mst_set_vert[MAX];
		int dist[MAX];
		int mst_vert_cnt=0;

		//initially all the vertices are unmarked i.e. not yet added into SPT set of vertices
		//& distance of all vertices from the given source vertex is INF
		for( int v = 0 ; v < vert_cnt ; v++ )
		{
			mst_set_vert[v] = false;
			dist[v] = INF;
		}

		//distance of source vertex from source vertex is 0
		dist[source] = 0;
		cout << "MST SET OF VERTICES IS: { ";
		while( mst_vert_cnt < vert_cnt )
		{
			int min_key_vert = get_min(dist, mst_set_vert);
			mst_set_vert[min_key_vert] = true;//add min_key_vert into MST set of vertices
			mst_vert_cnt++;
			cout << setw(4) << left << min_key_vert;

			//update distance of all its (min_key_vert) adjacent but unmarked
			//vertices to the min distance
			for( int v = 0 ; v < vert_cnt ; v++ )
			{
				if( mat[min_key_vert][v] != INF && mst_set_vert[v] == false
						&& dist[min_key_vert] + mat[min_key_vert][v] < dist[v] )
				{
					dist[v] = dist[min_key_vert] + mat[min_key_vert][v];
				}
			}//end of for loop
		}//end of while loop
		cout << " } " << endl;

		cout << "shortest distance of all vertices from the given source vertex is: " << endl;

		for( int v = 0 ; v < vert_cnt ; v++ )
		{
			cout << source << " -> " << v << " : " << dist[v] << endl;
		}
	}


	void prims(int root)
	{
		bool mst_set_vert[MAX];
		int vert_key[MAX];
		int mst_vert_cnt=0;
		int parent[MAX];

		//initially all the vertices are unmarked i.e. not yet added into MST set of vertices
		//& key values of all vertices are INF & parent of each vertex is -1
		for( int v = 0 ; v < vert_cnt ; v++ )
		{
			mst_set_vert[v] = false;
			vert_key[v] = INF;
			parent[v] = -1;
		}

		//key value of root vertex is 0
		vert_key[root] = 0;
		parent[root] = root;

		cout << "MST SET OF VERTICES IS: { ";
		while( mst_vert_cnt < vert_cnt )
		{
			int min_key_vert = get_min(vert_key, mst_set_vert);
			mst_set_vert[min_key_vert] = true;//add min_key_vert into MST set of vertices
			mst_vert_cnt++;
			cout << setw(4) << left << min_key_vert;

			//update key value of all its adjacent but unmarked vertices
			for( int v = 0 ; v < vert_cnt ; v++ )
			{
				if( mat[min_key_vert][v] != INF && mst_set_vert[v] == false
						&& mat[min_key_vert][v] < vert_key[v] )
				{
					vert_key[v] = mat[min_key_vert][v];
					parent[v] = min_key_vert;
				}
			}//end of for loop
		}//end of while loop
		cout << " } " << endl;

		int weight_spt = 0;
		cout << "MST EDGES ARE : " << endl;
		for( int i = 0 ; i < vert_cnt ; i++ )
		{
			if( i != root )
			{
				cout << parent[i] << "--" << i << " : " << mat[ parent[i] ][i] << endl;
				weight_spt += mat[ parent[i] ][ i ];
			}
		}
		cout << "weight of min spanning tree is: " << weight_spt << endl;

	}
};

int main(void)
{
	graph g1;

	g1.accept_graph();
	g1.display_graph();

	
	int source;
	cout << "enter source vertex: ";
	cin >> source;
	g1.dijsktras(source);
	/*
	int root;
	cout << "enter root vertex: ";
	cin >> root;

	g1.prims(root);*/
	return 0;
}












