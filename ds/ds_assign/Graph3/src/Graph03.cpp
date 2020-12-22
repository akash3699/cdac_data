

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
using namespace std;

#define MAX 10
#define INF 9999

class graph
{
private:
	int v_count;
	int e_count;
	vector< list<int> > g;

public:
	graph(void)
	{
		this->v_count=0;
		this->e_count=0;
	}

	void acceptData(void)
	{
		cout<<"Enter the V Count";
		cin>>this->v_count;
		cout<<"Enter the Edge Count";
		cin>>this->e_count;

		for(int i=0;i<v_count;i++)
		{
			list<int> empty_list;
			g.push_back(empty_list);
		}


		for(int i=0;i<this->e_count;i++)
		{
			int v1,v2;
			cin>>v2>>v1;
			g[v2].push_back(v1);
			g[v1].push_back(v2);//directed graph
		}


	}


	void displayData(void)
	{
		list<int>::iterator itr;
		for(int i=0;i<v_count;i++)
		{
			cout << "[ " << i << " ] " << " => ";
			for(itr=g[i].begin();itr!=g[i].end();itr++)
			{

					cout<<*itr<<" -> ";

			}
			cout<<"NULL"<<endl;
		}
	}



};



int main() {

	graph g;
	g.acceptData();
	g.displayData();

	return 0;
}
