
//Time complexity - O(log(n))
//Space complexity - O(log(n)) because number of recurisve call depends on size of array

#include<iostream>
using namespace std;

int bSearch(int arr[], int low, int high, int x)
{
	if(low > high)
		return -1;

	int mid = (low+high)/2;

	if(arr[mid] == x)
		return mid;

	else if(arr[mid] > x)
		return bSearch(arr, low, mid-1, x);

	else
		return bSearch(arr, mid+1, high, x);
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

	cout << bSearch(arr, 0, size-1, element);

	return 0;
}
