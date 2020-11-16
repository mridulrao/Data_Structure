/* Find the repeating element in the array but there are some conditions - 
The array size >= 2
Only one element should repeat(Any number of times)
All the elements from 0 to max[arr] should be present 
eg if max[arr] = 5
then 0,1,2,3,4,5 must be present at least one time in the array

*/

#include<bits/stdc++.h>
#include<iostream>
#include<cmath>

using namespace std;

int repeat(int arr[], int n)
{
	bool visit[n];

	memset(visit, false, sizeof(visit)); // initialises the array positions with false

	for(int i = 0; i < n;i++)
	{
		if(visit[arr[i]])
			return arr[i];
		visit[arr[i]] = true;
	}

	return -1;
}

int main()
{
	int arr[] = {0, 2, 1, 3, 2, 2};
	int n = 6;

	cout << repeat(arr, n);

	return 0;
}


