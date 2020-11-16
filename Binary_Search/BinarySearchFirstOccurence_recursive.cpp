
/* this is the recursive approach for finding
the first occurencec of an element in an sorted array.
Binary search in iterative code is better in terms of space complexity than recursive approach
time complexity is same for both. */

#include<iostream>
using namespace std;

int firstOcc(int arr[], int low, int high, int x)
{
	if(low > high)
		return -1;

	int mid = (low + high)/2;

	if(x > arr[mid])
		return firstOcc(arr, mid + 1, high, x);

	else if(x < arr[mid])
		return firstOcc(arr, low, mid - 1, x);

	else //when x == arr[mid]
	{
		if( mid == 0 || arr[mid - 1] != arr[mid])
			return mid;

		else
			return firstOcc(arr, low, mid - 1, x);
	}
}

int main()
{
	int size;
	cout << "Enter size of the array" << endl;
	cin >> size;
	int arr[size];
	for (int i=0;i<size;i++)
		cin >> arr[i];

	int element;

	cout << "Enter element to search" << endl;
	cin >> element;

	cout << firstOcc(arr, 0, size-1, element);

	return 0;
}
