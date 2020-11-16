
//this is finding the first occurence of an element in a sorted array using binary search
//binary search starts from middle

#include<iostream>
using namespace std;

int firstOcc(int arr[], int n,int x)
{
	int low = 0;
	int high = n-1;

	while(low <= high)
	{
		int mid = (low + high)/2;

		if(x > arr[mid])
			low = mid + 1;

		else if(x < arr[mid])
			high = mid - 1;

		else // when mid[arr] == x
		{
			//check whether previous element is not same as arr[mid] cause then the previous
			//element will be the first occurence
			if(mid == 0 || arr[mid - 1] != arr[mid])
				return mid;

			else 
				high = mid - 1;
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

	cout << firstOcc(arr, size, element);

	return 0;
}
