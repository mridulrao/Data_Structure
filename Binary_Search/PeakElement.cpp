
/* peak elememt menas that it is greater than its right neighbour as well as
left nieghbour. Here the array is not sorted 
Watch this video to get better understanding of code - https://practice.geeksforgeeks.org/tracks/DSASP-Searching/?batchId=154
*/

#include<iostream>
using namespace std;

int getPeak(int arr[], int n)
{
	int low = 0, high = n - 1;

	while(low <= high)
	{
		int mid = (low + high)/2;

		if((mid == low || arr[mid - 1] <= arr[mid]) && (mid == n-1 || arr[mid + 1] <= arr[mid]))
			return arr[mid];
		if(mid > 0 && arr[mid - 1] >= arr[mid])
			high = mid - 1;
		else 
			low = mid + 1;
	}
	return -1; // this condition will never run cause there will exist at least one peak element in an array
}

int main()
{
	int size;
	cout << "Enter size of the array ";
	cin >> size;

	int arr[size];

	for (int i = 0; i<size; i++)
		cin >> arr[i];

	cout << "Peak element(s) is/are " << getPeak(arr, size);

	return 0;
}