

//Time complexity - O(log(n))
//Space complexity - O(1)  //cause in the loop we are using constant values not arrays.


#include<iostream>
using namespace std;

int bsearch(int arr[], int n, int x)
{
	int low = 0, high = n-1;

	while(low <= high) 
	{
		int mid = (low+high)/2;

		if(arr[mid] == x)
			return mid;

		else if(arr[mid] > x)
			high = mid-1;

		else // arr[mid] < x
			low = mid+1;
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

	cout << bsearch(arr, size, element);

	return 0;
}