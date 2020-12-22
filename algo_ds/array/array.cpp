/*
 * array.cpp
 *
 *  Created on: 26-Sep-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include"array.h"

int comparisons=0;

bool linear_search(int arr[], int key)
{
	comparisons=0;
	for( int index = 0 ; index < SIZE ; index++ )
	{
		comparisons++;
		if( arr[index] == key )
			return true;
	}
	return false;
}

void accept_array_elements(int arr[])
{
	cout << "enter array ele's: " << endl;
	for( int index = 0 ; index < SIZE ; index++ )
	{
		cout << "enter arr[ " << index << " ] : ";
		cin >> arr[ index ];
	}
}

void display_array_elements(int arr[])
{
	cout << "entered array ele's are: ";
	for( int index = 0 ; index < SIZE ; index++ )
		cout << setw(4) << left << arr[index];

	cout << endl;
}

int array_sum(int arr[])
{
	int sum=0;

	for( int index = 0 ; index < SIZE ; index++ )
		sum += arr[index];

	return sum;
}

int rec_array_sum(int arr[], int index)
{
	if( index == SIZE )
		return 0;

	return ( arr[index] + rec_array_sum(arr, index+1));
}










