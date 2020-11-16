/* 
Two pointer approach will have two pointer 
one in beginning of the array and one in end (the array is sorted)
we will shift the left pointer(in the begnning of array) if the sum of two 
pointer is less than desired sum otherwise we shift right pointer if sum of pointer 
is greater than desired sum

*/

#include<bits/stdc++.h>
using namespace std;

bool isPresent(int arr[], int n, int sum)
{
	int l = 0, h = n - 1;
	int mid;

	while(l <= h)
	{
		if(arr[l] + arr[h] == sum)
			return true;
		else if(arr[l] + arr[h] > sum)
			h--;
		else
			l++;
	}
	return false;
}

int main()
{
	int size;
	cout << "Enter the size of array ";
	cin >> size;

	int arr[size];
	for(int i = 0;i < size; i++)
		cin >> arr[i];

	int sum;
	cout << "Enter the desired sum ";
	cin >> sum;

	cout << isPresent(arr, size, sum);

	return 0;
}