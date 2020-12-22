#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <limits.h>
#include <vector>
#include <iterator>
#include <algorithm>



using namespace std;

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
	edge(int src=0, int dest=0,int weight=0)
	{
		this->src=src;
		this->dest=dest;
		this->weight=weight;
	}

	friend ostream & operator<<(ostream &out, const edge &other)
	{
		out<<other.src<<" ";
		out<<other.dest<<" ";
		out<<other.weight<<" "<<endl;

		return out;
	}
	friend class graph;
};

class graph
{
private:
	int v_count;
	int e_count;

	int mat[MAX][MAX];

	vector<edge> arr;

public:
	graph(void)
	{
		this->v_count=0;
		this->e_count=0;
		for( int i = 0 ; i < MAX ; i++ )
			for( int j = 0 ; j < MAX ; j++ )
				mat[i][j] = INF;


	}

	void acceptData(void)
	{
		cout<<"Enter the V Count";
		cin>>this->v_count;
		cout<<"Enter the Edge Count";
		cin>>this->e_count;


		for(int i=0;i<this->e_count;i++)
		{
			int v1,v2,temp;
			cin>>v2>>v1>>temp;

			mat[v2][v1]=temp;
			mat[v1][v2]=temp;

			edge e1(v1,v2,temp);
			arr.push_back(e1);
		}
	}

	void displayEdges(void)
	{
		vector<edge>::iterator itr;
		for(itr=arr.begin();itr!=arr.end();itr++)
			cout<<*itr<<endl;
	}

	void displayData(void)
	{

		//cout<<"Weight of graph is "<<weight_graph<<endl;
		cout<<endl;
		for(int i=0;i<v_count;i++)
		{
			for(int j=0;j<v_count;j++)
			{
					if(mat[i][j]!=INF)
					cout<<setw(4)<<left<<mat[i][j];
					else
						cout<<setw(4)<<left<<"$";

			}
			cout<<endl;
		}
		cout << endl;
		cout << "edges are: " << endl;
		displayEdges();
		cout<<"===================";
	}

	void kruskals()
	{
		sort_edges();
		displayEdges();
		int x=0;
		vector<edge> mst_edges;

		for(int i=0;i<v_count;i++)
		{
			parent[i]=i;
			g_rank[i]=0;

		}

		while(mst_edges.size()<v_count-1)
		{
			edge next=arr[x++];
			int x= root(next.src);
			int y= root(next.dest);

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

	void sort_edges()
	{
		for(unsigned int i=0;i<this->arr.size()-1;i++)
		{
			for(unsigned int j=i+1;j<this->arr.size();j++)
			{
				if(arr[i].weight>arr[j].weight)
				{
					edge temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}
		}
	}
	int root(int i)
	{
		if( i != parent[i] )
			parent[i] = root( parent[i] );
		return parent[i];
	}

};



int main() {

	graph g;
	g.acceptData();
	g.displayData();

	g.kruskals();



	return 0;
}
