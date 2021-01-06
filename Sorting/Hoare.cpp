/*
 This is another type of partition method using in quick sort 
apart from lumoto partition method 
In lumoto last element is cosidered as pivot point but in hoare partition first element is 
pivot point 

*/

// Quick sort is not stable algorithm but used in most languages
//specially for sorting of arrays 

/* note that we have used do-while loops here. 
That is they will run atleast ones when they are called.
Since first the i and j variable are assigned values which are out of bound for the array
but when the do-while loop is called they are incremented first, becuase of which 
they are assigned values present inside the array 

*/

#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int h)
{
	int pivot = arr[l];
	int i = l-1;
	int j = h+1;

	while(true)
	{
		do
		{
			i++;
		}while(arr[i] < pivot);

		do
		{
			j--;
		}while(arr[j] > pivot);

		if(i >= j)
		{
			return j;
		}

		swap(arr[i], arr[j]);
	}
}

int main()
{
	int arr[] = {5, 3, 8, 4, 2, 7, 1, 10};
	int n = sizeof(arr)/sizeof(arr[0]);

	partition(arr, 0, n-1);

	for(int x:arr)
		cout << x << " ";

	return 0;
}