//============================================================================
// Name        : selection_sort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;
#define SIZE 8
#define SWAP(a,b) { int t=a; a=b; b=t;}

class sort
{

private:
	int arr[8]={50,80,40,30,10,60,70,20};
	//int arr[];
public:
	sort(void)
	{
		//this->arr=){50,80,40,30,10,60,70,20};

	}

	void insertion_sort(void)
	{
		int iterations=0;
		int while_cnt=0;

		for( int i = 1 ; i < SIZE ; i++ )
		{
			int key = arr[i];
			int j = i-1;

			iterations++;
			//start comparing key ele with ele's in a left hand from right to left
			while( j >= 0 && key < arr[j] )
			{
				arr[j+1] = arr[j];//shift larger ele's towards its right
				j--;
				while_cnt++;
			}
			//insert key at its appropriate position
			arr[j+1] = key;
		}

		cout << "no. of iterations are: " << iterations << endl;
		cout << "while_cnt : " << while_cnt << endl;
	}

	void bubble_sort(void)
	{
		int iterations=0;
		int comparisons=0;
		bool flag = true;

		for( int it = 0 ; it < SIZE-1 && flag == true ; it++ )
		{
			flag = false;
			iterations++;
			for( int pos = 0 ; pos < SIZE-it-1 ; pos++ )
			{
				comparisons++;
				//if ele's which are two consecutive pos are not in order
				if( arr[ pos ] > arr[ pos+1 ] )
				{
					flag = true;
					SWAP(arr[ pos ], arr[ pos+1 ]);
				}
			}

			//cout << "after iteration : " << iterations; display_array_elements();
		}

		cout << "no. of iterations are	: " << iterations << endl;
		cout << "no. of comparisons are	: " << comparisons << endl;
	}

	void selection_srt(void)
	{

		for(int i =0 ; i<SIZE-1; i++)
		{
			for(int j=i+1; j<SIZE; j++)
			{
				if(arr[i]>arr[j])
					SWAP(arr[i],arr[j]);

			}
		}

	}

	void display_array_elements(void)
	{
		cout << "array ele's are: ";
		for( int index = 0 ; index < SIZE ; index++ )
			cout << setw(4) << left << arr[index];
		cout << endl;

	}
};



int main() {


	sort s1;
	s1.insertion_sort();
	s1.display_array_elements();

	return 0;
}
