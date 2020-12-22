
#include <iostream>
#include<string>
#include<list>
#include<iterator>
using namespace std;
class emp
{
private:
	int empid;
	string name;
	float salary;

public:
	emp(void)
	{
		this->empid=0;
		this->name="";
		this->salary=0.0;
	}

	emp(const emp &other)
	{
		this->empid=other.empid;
		this->name=other.name;
		this->salary=other.salary;
	}
	friend ostream &operator<<(ostream &cout,const emp &e1);
	friend istream &operator>>(istream &cin,emp &e1);

};//end of emp class

istream &operator>>(istream &cin,emp &e1)
{
	cout<<"\nEnter EMP ID ";
	cin>>e1.empid;
	cout<<"\nEnter EMP Name ";
	cin>>e1.name;
	cout<<"\nEnter EMP Salary ";
	cin>>e1.salary;
return cin;

}

ostream &operator<<(ostream &cout,const emp &e1)
{
	cout<<e1.empid<<"	";
	cout<<e1.name<<"	";
	cout<<e1.salary<<"	";
return cout;

}


int menuChoice(void)
{
	int ch;
	cout<<endl;
	cout<<"0) Exit"<<endl;
	cout<<"1) Insert EMP"<<endl;
	cout<<"2) Delete Last EMP"<<endl;
	cout<<"3) Display all EMP"<<endl;
	cout<<" ENter choice"<<endl;
	cin>>ch;
	return ch;
}

int main() {

	list<emp> l1;
	emp e1;
	int ch=0;

	while((ch=menuChoice())!=0)
	{
		switch(ch)
		{
		case 1:
			cin>>e1;
			l1.push_back(e1);

			break;

		case 2:
			l1.pop_back();

			break;

		case 3:
			list<emp>::iterator itr;
			for(itr=l1.begin();itr!=l1.end();itr++)
				cout<<*itr;
			break;


		}//end of switch

	}//end of while


	/*cin>>e1;
	l1.add_to_last_position(e1);
	l1.displayList();
	l1.delete_node_at_last_position();
	l1.displayList();*/
	return 0;
}
