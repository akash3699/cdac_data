

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <limits.h>
using namespace std;

#define MAX 10
#define INF 9999


class graph
{
private:
	int v_count;
	int e_count;
	int weight_graph;
	int arr [ MAX ] [ MAX ];

public:
	graph(void)
	{
		this->v_count=0;
		this->e_count=0;
		this->weight_graph=0;

		for (int index=0;index<MAX;index++)
			for(int j=0;j<MAX;j++)
				arr[index][j]=INF;

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
			arr[v2][v1]=temp;
			arr[v1][v2]=temp;//directed graph
			this->weight_graph += temp;
		}


	}


	void displayData(void)
	{

		cout<<"Weight of graph is "<<weight_graph<<endl;
		for(int i=0;i<v_count;i++)
		{
			for(int j=0;j<v_count;j++)
			{
				if(arr[i][j]!=INF)
					cout<<setw(4)<<left<<arr[i][j];
				else
					cout<<setw(4)<<left<<"0";
			}
			cout<<endl;
		}
	}

	int getMin(int dist[], bool marked[])
	{
		int min=0;
		int min_weight=INF;
		for(int i=0;i<v_count;i++)
		{
			if(marked[i]==false && dist[i]<min_weight)
			{
				min=i;
				min_weight=dist[i];
			}

		}

		return min;
	}
	void dijkstra( int src)
	{

		bool marked[MAX];
		int dist[MAX];
		int mst_vert_cnt=0;



		for(int i=0;i<v_count;i++)
		{
			marked[i]=false;
			dist[i]=INF;
		}
		cout<<"Set of vertices are =";
		dist[src]=0;
		while(mst_vert_cnt<v_count)
		{
			int min_key_vert=getMin(dist,marked);
			marked[min_key_vert]=true;
			mst_vert_cnt++;

			cout << setw(4) << left << min_key_vert;
			//cout<<min_key_vert;

			for(int i=0;i<v_count;i++)
			{
				if(arr[min_key_vert][i]!=INF && marked[i]==false && dist[min_key_vert]+arr[min_key_vert][i] < dist[i])
				{
					dist[i] = dist[min_key_vert]+arr[min_key_vert][i];

				}
			}

		}


		for( int i = 0 ; i < v_count ; i++ )
		{
			cout << src << " -> " << i << " : " << dist[i] << endl;
		}

	}

	void prims( int root)
		{

			bool marked[MAX];
			int v_key[MAX];
			int parent[MAX];
			int mst_vert_cnt=0;



			for(int i=0;i<v_count;i++)
			{
				marked[i]=false;
				v_key[i]=INF;
				parent[i]=-1;
			}
			cout<<"Set of vertices are =";
			v_key[root]=0;
			parent[root]=root;
			while(mst_vert_cnt<v_count)
			{
				int min_key_vert=getMin(v_key,marked);
				marked[min_key_vert]=true;
				mst_vert_cnt++;

				cout << setw(4) << left << min_key_vert;
				//cout<<min_key_vert;

				for(int i=0;i<v_count;i++)
				{
					if(arr[min_key_vert][i]!=INF && marked[i]==false && arr[min_key_vert][i] < v_key[i])
					{
						v_key[i] = arr[min_key_vert][i];
						parent[i]=min_key_vert;
					}
				}

			}


		int weight_spt = 0;
		cout << "MST EDGES ARE : " << endl;
		for( int i = 0 ; i < v_count ; i++ )
		{
			if( i != root )
			{
				cout << parent[i] << "--" << i << " : " << arr[ parent[i] ][i] << endl;
				weight_spt += arr[ parent[i] ][ i ];
			}
		}
		cout << "weight of min spanning tree is: " << weight_spt << endl;

		}



};



int main() {

	graph g;
	g.acceptData();
	//g.displayData();
	//int source;
	//cout<<"enter source";
	//cin>>source;
//	g.dijkstra(source);

	int root;
	cout<<"enter root";
	cin>>root;
	g.prims(root);


	return 0;
}
