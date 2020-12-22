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
#include<algorithm>
#include<iterator>

#define MAX 10
#define INF 9999

int parent[MAX];
int g_rank[MAX];

class edge
{
private:
	int src;
	int dest;
	int weight;
public:
	edge(int u=0, int v=0, int w=0)
	{
		this->src = u;
		this->dest = v;
		this->weight = w;
	}

	friend ostream& operator<<( ostream& out, edge& other )
	{
		out << other.src << "->" << other.dest << " : " << other.weight;
		return out;
	}
	friend class graph;
};

class graph
{
private:
	int mat[MAX][MAX];
	int vert_cnt;
	int edge_cnt;
	vector<edge> edges;
public:
	graph()
	{
		for( int i = 0 ; i < MAX ; i++ )
			for( int j = 0 ; j < MAX ; j++ )
				mat[i][j] = INF;
		this->vert_cnt = 0;
		this->edge_cnt = 0;
	}

	void accept_graph(void)
	{
		cout << "enter the no. of vertices: ";
		cin >> vert_cnt;
		cout << "enter the no. of edges: ";
		cin >> edge_cnt;
		for( int i = 0 ; i < edge_cnt ; i++ )
		{
			int from, to, weight;
			cout << "enter the edge: from to to & weight: ";
			cin >> from >> to >> weight;

			mat[from][to] = weight;
			mat[to][from] = weight;

			edge ed(from, to, weight);
			edges.push_back(ed);
		}
	}

	void display_graph(void)
	{
		cout << endl << "input graph is: " << endl;
		cout << "no. of vertices are: " << vert_cnt << endl;
		cout << "no. of edges are   : " << edge_cnt << endl;
		for( int i = 0 ; i < vert_cnt ; i++ )
		{
			for( int j = 0 ; j < vert_cnt ; j++ )
			{
				if( mat[i][j] != INF )
					cout << setw(4) << mat[i][j];
				else
					cout << setw(4) << "#";
			}
			cout << endl;
		}
		cout << endl;
		cout << "edges are: " << endl;
		display_edges();
	}

	void display_edges(void)
	{
		vector<edge>::iterator itr;
		for( itr = edges.begin() ; itr != edges.end() ; itr++ )
			cout << *itr << endl;
	}

	int root(int i)
	{
		if( i != parent[i] )
			parent[i] = root( parent[i] );
		return parent[i];
	}

	void combine(int x,int y)
	{
		int xroot = root(x);
		int yroot = root(y);

		if( g_rank[xroot] > g_rank[yroot] )
			parent[yroot] = xroot;
		else
		if( g_rank[xroot] < g_rank[yroot] )
			parent[xroot] = yroot;
		else
		{
			parent[yroot] = xroot;
			g_rank[xroot]++;
		}
	}

	void kruskals(void)
	{
		//sort the edges in an ascending order of their weights
		sort_edges();
		cout << "edges after sorting: " << endl;
		display_edges();


		//MST set of edges:
		vector<edge> mst_edges;
		int i = 0;
		//initially each vertex is parent of itself and rank of each vertex is 0
		for( int v = 0 ; v < vert_cnt ; v++ )
		{
			parent[v] = v;
			g_rank[v] = 0;
		}

		while( mst_edges.size() < vert_cnt-1 )
		{
			//select an edge from edge set
			edge next = edges[i++];

			int x = root(next.src);
			int y = root(next.dest);

			//if edge is not forming the cycle then we can add the edge into
			//the MST set of vertices
			if( x != y )
			{
				mst_edges.push_back(next);
				combine(x,y);
			}
		}
		int weight_spt = 0;
		cout << "MST SET EDGES IS: " << endl;

		vector<edge>::iterator itr;
		for( itr = mst_edges.begin() ; itr != mst_edges.end() ; itr++ )
		{
			cout << itr->src << " -> " << itr->dest << " : "  << itr->weight << endl;
			weight_spt += itr->weight;
		}

		cout << "Weight of SPT = " << weight_spt << endl;

	}

	void sort_edges(void)
	{

		for( unsigned int i = 0 ; i < edges.size()-1 ; i++ )
		{
			for( unsigned int j = i+1 ; j < edges.size() ; j++ )
			{
				if( edges[i].weight > edges[j].weight )
				{
					edge temp = edges[i];
					edges[i] = edges[j];
					edges[j] = temp;
				}
			}
		}
	}
};


int main(void)
{
	graph g1;

	g1.accept_graph();
	g1.display_graph();

	g1.kruskals();

	return 0;
}




