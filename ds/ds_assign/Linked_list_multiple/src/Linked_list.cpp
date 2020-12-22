
#include"list.h"
using namespace std;

int menuChoice(void);
int main() {

	list l1;
	int choice,no,rank;
	while((choice=::menuChoice())!=0)
	{
		switch(choice)
		{
		case 1:
			cout<<"Enter value"<<endl;
			cin>>no;
			l1.add_node_last(no);
			l1.traverselist();
			break;

		case 2:
			l1.deleteLast();
			l1.traverselist();

			break;

		case 3:
			l1.deleteFirst();
			l1.traverselist();
			break;

		case 4:
			l1.traverselist();
			break;

		case 5:
			l1.traverselist();
			cout<<endl;
			cout<<"Enter the rank of Node";
			cin>>rank;
			l1.deleteSpecific(rank);
			l1.traverselist();
			break;

		case 6:
			int data;
			cout<<"Enter element to Search";
			cin>>data;
			if(l1.searchData(data))
				cout<<"Element is found"<<endl;
			else
				cout<<"Element not found"<<endl;
			break;

		default:
			cout<<"Enter Correct Option";
			break;

		}

	}

	return 0;
}
