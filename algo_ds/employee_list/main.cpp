/*
 * main.cpp
 *
 *  Created on: 02-Oct-2019
 *      Author: sunbeam
 */
#include<iostream>
using namespace std;
#include<iomanip>
#include<string>
#include<list>
#include<iterator>

class employee
{
private:
	int empid;
	string name;
	float salary;
public:
	employee(int empid=0, string name=" ", float salary=0.0)
	{
		this->empid = empid;
		this->name = name;
		this->salary = salary;
	}

	//getter functions
	//setter functions
	//facilitators
	friend ostream& operator<<( ostream& out, employee& other )
	{
		out << setw(10) << left << other.empid;
		out << setw(20) << left << other.name;
		out << setw(10) << left << other.salary;
		return out;
	}
};

int main(void)
{
	list<employee> emp_list;

	emp_list.push_back( employee(111, "sachin", 1111.11) );
	emp_list.push_back( employee(222, "nilesh", 2222.22) );
	emp_list.push_back( employee(333, "sandeep", 3333.33) );
	emp_list.push_back( employee(444, "rakesh", 4444.44) );
	emp_list.push_back( employee(555, "amit", 5555.55) );


	list<employee>::iterator itr;
	cout << "list of employees is: " << endl;
	for( itr = emp_list.begin() ; itr != emp_list.end() ; itr++ )
		cout << *itr << endl;




	return 0;
}



