/*
 * main.cpp
 *
 *  Created on: 26-Sep-2019
 *      Author: sunbeam
 */
#include<iostream>
using namespace std;

#include"array.h"

int main(void)
{
	//int arr[SIZE] = {10,20,30,40,50,60,70,80};
	int arr[SIZE] = {10,20,30,40,50};
	//accept_array_elements(arr);
	display_array_elements(arr);
	//cout << "sum = " << array_sum(arr) << endl;
	//cout << "sum = " << rec_array_sum(arr,0) << endl;

	int key;
	cout << "enter the key: ";
	cin >> key;

	if( linear_search(arr, key) )
	{
		cout << "key exists in an array" << endl;
		cout << "no.of comparisons are: " << comparisons << endl;
	}
	else
	{
		cout << "key does not exists in an array" << endl;
		cout << "no.of comparisons are: " << comparisons << endl;
	}

	return 0;
}


