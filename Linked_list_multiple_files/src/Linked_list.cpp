
#include"list.h"
using namespace std;

int menuChoice(void);
int main() {

	list l1;
	int choice,no;
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

		default:
			cout<<"ENter correct choice";
			break;

		}






	}









	/*int no;
	cout<<"Enter value"<<endl;
	cin>>no;
	l1.add_node_last(no);
	cout<<"Enter value"<<endl;
	cin>>no;
	l1.add_node_last(no);
	cout<<"Enter value"<<endl;
	cin>>no;
	l1.add_node_last(no);
	l1.traverselist();
	cout<<endl;
	l1.deleteLast();
	l1.traverselist();
	cout<<endl;
	l1.deleteFirst();
	l1.traverselist();*/
	return 0;
}
