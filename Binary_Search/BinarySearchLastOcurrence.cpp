#include<iostream>
using namespace std;

int lastOcc(int arr[], int n, int x)
{
	int low = 0, high = n - 1;

	while(low <= high)
	{
		int mid = (low + high)/2;

		if (x > arr[mid])
			low = mid + 1;

		else if (x < arr[mid])
			high = mid - 1;

		else  //when arr[mid] == x 
		{
			if(mid == n - 1 || arr[mid + 1] != arr[mid])
				return mid;
			else
				low = mid + 1;
		}
	}
	return -1;
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

	cout << lastOcc(arr, size, element);

	return 0;
}