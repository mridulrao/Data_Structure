/* 
inversion is a pair of integer(x, y) in array where x < y and the indexes of 
y is gretaer than x. Simply saying in sorting the array , y will come before x.

We are using merge sort function 
Time complexity of merge sort  - O(nlog(n))
Space compelexity - O(n)
*/

#include<bits/stdc++.h>

using namespace std;

int countAndMerge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1; //dividing the array into two parts - left and right 
	int n2 = r - m;
	int left[n1], right[n2];

	// copying the elements in right and left array
	for(int i = 0;i < n1; i++)
		left[i] = arr[i + l];
	for (int j = 0;j < n2; j++)
		right[j] = arr[m + 1 + j];

	int res = 0; //count of inversion pairs
	int i = 0, j = 0, k = l;

	while(i < n1 && j < n2)
	{
		if(left[i] <= right[j]) 
		{
			arr[k++] = left[i++];
		}

		else // if element in the right is smaller than the element in left array, then that 
			//means the element in right array is inverted
		{
			arr[k++] = right[j++];
			res = res + (n1 - i); // since the left and right array are sorted, the element 
			// in the right array will be smaller than the elemnts in the left 
		}
	}

	// for remaining elements 

	while(i < n1)
		arr[k++] = left[i++];
	while(j < n2)
		arr[k++] = right[j++];

	return res;
}

int countInv(int arr[], int l, int r)
{
	int res = 0;
	if(l < r)
	{
		int m = (r + l)/2;
		res += countInv(arr, l, m);
		res += countInv(arr, m + 1, r);
		res += countAndMerge(arr, l, m, r);
	}
	return res;
}

int main()
{
	int arr[] = {2, 4, 1, 3, 5};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << countInv(arr, 0, n-1);

	return 0;
}
