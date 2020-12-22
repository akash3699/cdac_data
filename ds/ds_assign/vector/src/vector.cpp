
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator itr;
	for(itr=v.begin();itr!=v.end();itr++)
		cout<<*itr<<endl;

	v.pop_back();

	for(itr=v.begin();itr!=v.end();itr++)
			cout<<*itr<<endl;

	return 0;
}
