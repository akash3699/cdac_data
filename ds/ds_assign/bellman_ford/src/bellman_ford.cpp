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
	int dist[MAX];
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
			//mat[v1][v2]=temp;

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

	int getMinimun()
	{
		int temp=0;
		int cost=INF;
		for(int i=0;i<v_count;i++)
		{
			if(dist[i]!=INF && dist[i]<cost)
			{
				temp=i;
				cost=dist[i];
			}
		}

		return temp;
	}

	void bellman_ford(int source)
	{
		int cnt=0;
		//dist[source]=0;
		for(int i=0;i<v_count;i++)
					dist[i]=INF;
		dist[source]=0;

		while(cnt<v_count)
		{
			//int select_v=getMinimun();

			for(int i=0;i<v_count;i++)
			{
				if( mat[cnt][i]!=INF &&  mat[cnt][i]+dist[cnt] < dist[i] )
				{
					dist[i]=mat[cnt][i]+dist[cnt];
				}

			}
			cnt++;

		}

		displayDist();


	}

	void displayDist()
	{
		cout<<"displayDist"<<endl;
		for(int i=0;i<v_count;i++)
			cout<<i<<" 		"<<dist[i]<<"	"<<endl;
	}


};



int main() {

	graph g;
	g.acceptData();
	g.displayData();

	g.bellman_ford(0);



	return 0;
}
