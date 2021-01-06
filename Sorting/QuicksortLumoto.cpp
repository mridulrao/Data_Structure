/* this is sorting using lumoto partittion function.
Quick sort is unstable sorting algorithm and it worst case complexity is o(n^2)

it is very popular sorting algorithm and is used in many languages 

It is very useful in sorting arrays
Merge sort is useful in soritng linked list and large arrays
*/

#include<bits/stdc++.h>
using namespace std;


//this is lumoto function for creating partition 
int iPartition(int arr[], int l, int h)
{
	// l is the beginning of the array
	// h is last elemnt of the array
	int pivot = arr[h];
	int i = l-1; //start with assigning -1 value 

	for(int j = l;j<= h; j++)
	{
		if(arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	//the pivot element will not be sorted in the for loop, it needs to be swapped after all the 
	//elements smaller than it have already been placed at correct position  
	swap(arr[i+1], arr[h]);
	return i+1;
}

void qSort(int arr[], int l, int h)
{
	if(l < h)
	{
		int p = iPartition(arr, l, h);
		qSort(arr, l, p-1);
		qSort(arr, p+1, h);
	}
}

int main()
{
	int arr[] = {8, 4, 7, 9, 3, 10, 5};

	int n = 7; //size of the array

	qSort(arr, 0, n-1); // element will be stored till 6th index

	for(int x:arr)
		cout << x << " ";

	return 0;
}