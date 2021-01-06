// This is a stable sorting function 

#include<iostream>
#include<algorithm>

using namespace std;

void merge (int arr[], int l, int m, int h)
{
	// Creating arrays (left and righ)

	int n1 = m - l + 1;  //Length of left array 
	int n2 = h - m; //Length of right array 

	int left[n1]; 
	int right[n2];

	for(int i = 0; i < n1; i++)
		left[i] = arr[i+l];

	for(int i = 0; i < n2; i++)
		right[i] = arr[m+1+i];

	int i = 0, j = 0, k = l;

	// Sorting the array

	while(i < n1 && j < n2)
	{
		if(left[i] <= right[j])
			arr[k++] = right[j++];

		else
			arr[k++] = right[j++];
	}

	while(i < n1)
		arr[k++] = left[i++];

	while(j < n2)
		arr[k++] = right[j++];
}

int main()
{
	int a[] = {10, 15, 20, 40, 8, 11, 15, 22, 25};
	int l = 0, h = 8, m = 3;

	merge(a, l, m, h);

	for(int x: a)
		cout << x << " ";

	return 0;
}