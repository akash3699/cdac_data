

#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <list>
using namespace std;

#define MAX 10
#define INF 9999
class edge
{
private:
	int v;
	int w;
public:
	edge(int v=0, int w=0)
	{
		this->v = v;
		this->w = w;
	}

	friend ostream& operator<<( ostream& out, edge& other )
	{
		out << other.v << " : " << other.w;
		return out;
	}
};


class graph
{
private:
	int v_count;
	int e_count;
	vector< list<edge> > g;

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
			list<edge> e1;
			g.push_back(e1);
		}


		for(int i=0;i<this->e_count;i++)
		{
			int v1,v2,weight;
			cin>>v2>>v1>>weight;

			edge ed1(v2,weight);
			g[v2].push_back(ed1);
			edge ed2(v1,weight);
			g[v1].push_back(ed2);//directed graph
		}


	}


	void displayData(void)
	{
		list<edge>::iterator itr;
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
