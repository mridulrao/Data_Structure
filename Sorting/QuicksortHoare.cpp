/* This is implementation of quick sort using 
hoare partition 

Hoare partition is beter than lumoto but of them are not 
stable sorting 

The difference between them is lumoto places the 
pivot at its correct position whereas the hoare partiion 
does not place the element at its correct position 
*/

#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int h)
{
	int pivot = arr[l];
	int i = l - 1;
	int j = h + 1;

	while(true)
	{
		do
		{
			i++;
		}while(arr[i] < pivot)

		do
		{
			j--;
		}while(arr[j] > pivot)

		if(i >= j)
			return j;

		swap(arr[i], arr[j]);
	}
}

void qSort(int arr, int l, int h)
{
	if(l < h)
	{
		int p = partition(arr, l, h);
		qSort(arr, l, p); //if we had used lumoto, then we would have passed p-1
		//because in lumoto the pivot would have already be placed at its correct position, so we dont need to pass it in sorting function
		qSort(arr, p+1, h);
	}
}

int main()
{
	int arr[] = {8, 4, 7, 9, 3, 10, 5};
	int n = 7; //size of array

	qSort(arr, 0, n-1);

	for(int x:arr)
		cout << x <<" ";

	return 0;
}