/* Here we take an element and sort the array around it. This element is known as pivot
Generally we take last elemnt as pivot. If the element is not the last element in the array 
then we switch that element with the last element.

This solution is based when last element is pivot.
If an element is in between the array (and taken as pivot ) then we switch that element 
with the last elemnt.
To do that - 
Before assigning the pivot swap the positions. 

Swap is inbuilt function in cpp
*/

#include<bits/stdc++.h>
using namespace std;

int isPartition(int arr[], int l, int h)
{
	int pivot = arr[h]; // assign last elemt as pivot 
	int i = l - 1; // initiallt i will be -1

	for(int j = l; j <= h-1; j++) // this loop will swap only those value which are smaller than pivot 
		//and will place them at inde i
	{
		if(arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[h]);

	return i+1;
}

int main()
{
	int arr[] = {10, 80, 30, 90, 40, 50, 70};

	int n = sizeof(arr)/sizeof(arr[0]);

	isPartition(arr, 0, n - 1);

	for(int X: arr)
		cout << x << " ";

	return 0;
}