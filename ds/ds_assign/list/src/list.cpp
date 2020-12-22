
#include <iostream>
using namespace std;
#include <list>
#include <iterator>
int main() {

	list<int> l;
	l.push_back(15);
	l.push_back(25);
	l.push_back(35);
	l.push_back(45);
	l.push_back(55);

	list<int>::iterator itr;
	for(itr=l.begin();itr!=l.end();itr++)
		cout<<*itr<<endl;


	return 0;
}
