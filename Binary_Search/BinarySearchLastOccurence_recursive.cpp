#include<iostream>
using namespace std;

int lastOcc(int arr[], int low, int high, int x, int n)
{
	if(low > high)
		return -1;

	int mid = (low + high)/2;

	if(x > arr[mid])
		return lastOcc(arr, mid + 1, high, x, n);

	else if(x < arr[mid])
		return lastOcc(arr, low, mid - 1, x, n);

	else
	{
		if(mid == n-1 || arr[mid + 1] != arr[mid])
			return mid;
		else 
			return lastOcc(arr, mid + 1, high, x, n);
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

	cout << lastOcc(arr, 0, size - 1, element, size);

	return 0;
}