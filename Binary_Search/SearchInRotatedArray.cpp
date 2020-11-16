/* 
Rotated sorted array means =
arr = {1,2,3,4,5,6,7}

one time rotated, arr will become = 
arr = {2,3,4,5,6,7,1}
if the mid is 5, then left half of the array is sorted 

second time rotated, arr will become = 
arr = {3,4,5,6,7,1,2}

if we keep on rotating the array, eventually the right half of the array will become sorted
*/

#include<iostream>
using namespace std;

int search(int arr[], int n, int x)
{
	int low = 0, high = n - 1;

	while(low <= high)
	{
		int mid = (low + high)/2;

		if(arr[mid] == x)
			return mid;

		if(arr[low] < arr[mid]) // it means the left half of array is sorted 
		{
			if(x >= arr[low] && x < arr[mid])
				high = mid - 1;
			else 
				low = mid + 1;
		}
		else  // it means the right half is sorted 
		{
			if(x > arr[mid] && x <= arr[high])
				low = mid + 1;
			else 
				high = mid + 1;
		}
	}
	return -1;
}

int main()
{
	int size;
	cout << "Enter the size ";
	cin >> size;
	int arr[size];

	for (int i=0;i < size;i++)
		cin >> arr[i];

	int element;
	cout << "Enter the element to search ";
	cin >> element;

	cout << search(arr, size, element);

	return 0;
}
