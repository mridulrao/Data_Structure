/* when the size of an array is infinite it is imposiible to calculate the size 
and find middle term (for applying binary search) as value of n(size) is very large 
so we multiply the index position by 2 until we reach to an element which is greater 
or equal to desired element and then aplly binary search between that range to get desired 
number.  */

#include<iostream>
using namespace std;

int bSearch(int arr[], int low, int high, int x)
{
	if(low > high)
		return -1;

	int mid = (low + high)/2;

	if(arr[mid] == x)
		return mid;

	else if (arr[mid] > x)
		return bSearch(arr, low, mid - 1, x);

	else
		return bSearch(arr, mid + 1, high, x);
}

int search(int arr[], int x)
{
	if(arr[0] == x)
		return 0;

	int i = 1; // we cant initialize with 0 because 0*2 = 0 

	while(arr[i] < x)
		i = i*2;

	if(arr[i] == x)
		return i;

	return bSearch(arr, i/2 + 1, i-1, x);
}

int main()
{
	int size;
	cout << "Enter the size of array ";
	cin >> size;

	int arr[size];

	for (int i = 0;i<size;i++)
		cin >> arr[i];

	int element;
	cout << "Enter the element to find ";
	cin >> element;

	cout << search(arr, element);

	return 0;
}