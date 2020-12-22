#include <iostream>
using namespace std;


class binarysearch
{

public:
	bool binary_search(int arr[],int key)
	{
		int left =0;
		int right=7;
		int mid;
		while(left<=right)
		{
			mid= (left+right)/2;
			if(arr[mid]==key)
			{
				return true;
			}

			if(key < arr[mid])
			{
				right=mid-1;
			}
			else
				left=mid+1;
		}




		return false;
	}

	bool binary_search_rec(int arr[],int left,int right,int key)
	{
	//	int left =0;
		//int right=7;
		int mid;
		while(left<=right)
		{
			mid= (left+right)/2;
			if(arr[mid]==key)
			{
				return true;
			}

			if(key < arr[mid])
			{
				//right=mid-1;
				return binary_search_rec(arr,left,mid-1,key);
			}
			else
			{	//left=mid+1;
				return binary_search_rec(arr,mid+1,right,key);
			}
		}
		return false;
	}

};




int main() {
	int arr[]={10,20,30,40,50,60,70,80};
	//int arr[]={50,80,40,30,10,60,70,20};
	binarysearch b1;
	/*if(b1.binary_search(arr,51))
		cout<<"element found";
	else
		cout<<"element not found";*/

	if(b1.binary_search_rec(arr,0,7,50))
		cout<<"element found";
	else
		cout<<"element not found";

	return 0;
}
