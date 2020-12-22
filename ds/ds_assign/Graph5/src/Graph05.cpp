

#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <iterator>
using namespace std;

#define MAX 10

class graph
{
private:
	int v_count;
	int e_count;
	int arr [ MAX ] [ MAX ];

public:
	graph(void)
	{
		this->v_count=0;
		this->e_count=0;

		for (int index=0;index<MAX;index++)
			for(int j=0;j<MAX;j++)
				arr[index][j]=0;

	}

	void acceptData(void)
	{
		cout<<"Enter the V Count";
		cin>>this->v_count;
		cout<<"Enter the Edge Count";
		cin>>this->e_count;


		for(int i=0;i<this->e_count;i++)
		{
			int v1,v2;
			cin>>v2>>v1;
			arr[v2][v1]=1;
			arr[v1][v2]=1;//directed graph
		}


	}


	void displayData(void)
	{
		for(int i=0;i<v_count;i++)
		{
			for(int j=0;j<v_count;j++)
				cout<<setw(4)<<left<<arr[j][i];
			cout<<endl;
		}
	}

	void dfs_traversal(int start)
	{
		stack<int> s;
		bool marked[MAX];

		for(int i=0;i<v_count;i++)
			marked[i]=false;

		s.push(start);
		marked[start]=true;

		while(!s.empty())
		{
			int trav = s.top(); s.pop();
			cout << setw(4) << left << trav;
			for(int i=0;i<v_count;i++)
			{
				if(arr[trav][i]!=0 && marked[i]==false)
				{
					s.push(i);
					marked[i] = true;
				}
			}


		}
	}

	void bfs_traversal(int start)
		{
			queue<int> s;
			bool marked[MAX];

			for(int i=0;i<v_count;i++)
				marked[i]=false;

			s.push(start);
			marked[start]=true;

			while(!s.empty())
			{
				int trav = s.front(); s.pop();
				cout << setw(4) << left << trav;
				for(int i=0;i<v_count;i++)
				{
					if(arr[trav][i]!=0 && marked[i]==false)
					{
						s.push(i);
						marked[i] = true;
					}
				}


			}
		}

	bool is_connected(int source)
		{
			stack<int> s;
			bool marked[MAX];
			int connected_vert_cnt = 0;


			for( int v = 0 ; v < v_count ; v++ )
				marked[v] = false;


			s.push(source);
			marked[source] = true;

			while( !s.empty() )
			{

				int trav = s.top(); s.pop();


				for( int v = 0 ; v < v_count ; v++ )
				{
					if( arr[trav][v] != 0 && marked[v] == false )
					{
						s.push(v);
						marked[v] = true;
						connected_vert_cnt++;

						if( connected_vert_cnt == v_count-1 )
							return true;
					}
				}
			}
			cout << endl;

			return ( ( connected_vert_cnt == v_count-1 ) ? true : false );
		}

};



int main() {

	graph g;
	g.acceptData();
	g.displayData();

	cout<<"DFS Traversal"<<endl;
	g.dfs_traversal(0);
	cout<<endl;
	cout<<"BFS Traversal"<<endl;
	g.bfs_traversal(0);
	cout<<endl;
	(g.is_connected(0)) ? cout<<"is connected":cout<<"Not COnnected";

	return 0;
}
