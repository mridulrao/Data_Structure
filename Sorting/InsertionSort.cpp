/* 
It is a stable sorting algorithm 
When we have have small array input, insertion sort is the best sorting algorithm (for short datatypes)
Python inbuilt sort function uses TIM sort(insertion + Merge sort)
C++ inbuilt sort is made of insertion + merge + Heap sorting algorithms 

Very often used in sorting algorithm 

Worst case - when the array is reverse sorted - O(n^2)
Best case - When array is already sorted - O(n)
*/

#include<iostream>
#include<algorithm>

using namespace std;

void iSort(int arr[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while(j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int main()
{
	int arr[] = {50, 20, 40, 60, 10, 30};

	int n = sizeof(arr)/sizeof(arr[0]);

	iSort(arr, n);

	for(auto x: arr) // See sort function.cpp for explanation of this loop
		cout << x << " ";

	return 0;
}