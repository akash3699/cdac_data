

#include <iostream>
#include <iomanip>
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



};



int main() {

	graph g;
	g.acceptData();
	g.displayData();

	return 0;
}
