/*
 * main.cpp
 *
 *  Created on: 27-Sep-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>

#define SIZE 8

int comparisons=0;

void display_array_elements(int arr[]);
bool linear_search(int arr[], int key);
bool updated_linear_search(int arr[], int key);
bool binary_search(int arr[], int key);
bool rec_binary_search(int arr[], int left, int right, int key);

int main(void)
{
	int arr[SIZE] = {10,20,30,40,50,60,70,80};

	display_array_elements(arr);

	int key;
	cout << "enter the key: ";
	cin >> key;
	//if( linear_search(arr, key) )
	//if( updated_linear_search(arr, key) )
	//if( binary_search(arr, key))

	if( rec_binary_search(arr, 0, SIZE-1, key))
	{
		cout << "key is found in an array ..." << endl;
		//cout << "no. of comparisons are: " << comparisons << endl;
	}
	else
	{
		cout << "key is not found in an array ..." << endl;
		//cout << "no. of comparisons are: " << comparisons << endl;
	}
	return 0;
}

bool rec_binary_search(int arr[], int left, int right, int key)
{
	if( left > right )
		return false;

	int mid = (left+right)/2;

	if( key == arr[mid] )
		return true;

	if( key < arr[mid] )
		return rec_binary_search(arr, left, mid-1, key);
	else
		return rec_binary_search(arr, mid+1, right, key);
}


bool binary_search(int arr[], int key)
{
	int left = 0;
	int right = SIZE-1;

	comparisons=0;
	while( left <= right )
	{
		//calculate mid pos -- divide array into two sub arrays
		int mid = (left+right)/2;

		//if key ele is exists at mid pos -- return true
		comparisons++;
		if( key == arr[mid] )
			return true;

		//if not either we will search key into left sub array or into the right sub array
		if( key < arr[mid] )
			right = mid-1;
		else
			left = mid+1;
	}//end of while loop
	return false;
}

bool updated_linear_search(int arr[], int key)
{
	comparisons=0;
	for( int index = 0 ; index < SIZE && key >= arr[ index ] ; index++ )
	{
		comparisons++;
		if( arr[ index ] == key )
			return true;
	}

	return false;
}

bool linear_search(int arr[], int key)
{
	comparisons=0;
	for( int index = 0 ; index < SIZE ; index++ )
	{
		comparisons++;
		if( arr[ index ] == key )
			return true;
	}

	return false;
}

void display_array_elements(int arr[])
{
	cout << "array ele's are: ";
	for( int index = 0 ; index < SIZE ; index++ )
		cout << setw(4) << left << arr[index];
	cout << endl;

}
