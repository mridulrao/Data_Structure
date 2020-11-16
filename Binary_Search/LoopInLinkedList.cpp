/* It is the extension of RepeatingElement problem

We have to check for loop in the array(which we will traverse like likned list)
The condition mentioned in RepeatingElement mustr also be followed here.

*/


//Here the condition is that array should not have zero as an element 

/*
#include<iostream>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int repeat (int arr[], int n)
{
	int slow = arr[0], fast = arr[0];

	do
	{
		slow = arr[slow];
		fast = arr[arr[fast]];
	}while(slow != fast);

	slow = arr[0];

	while(slow != fast)
	{
		slow = arr[slow];
		fast = arr[fast];
	}

	return slow;
}

int main()
{
	int arr[] = {1, 3, 2, 4, 6, 5, 7, 3};
	int n = 8;

	cout << repeat(arr, n);

	return 0;
}

*/

// When we have zero as the smallest element (this method prevent unwanted cycles)

#include<iostream>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int repeat (int arr[], int n)
{
	int slow = arr[0] + 1, fast = arr[0] + 1;

	do
	{
		slow = arr[slow] + 1;
		fast = arr[arr[fast] + 1] + 1;
	}while(slow != fast);

	slow = arr[0] + 1;

	while(slow != fast)
	{
		slow = arr[slow] + 1;
		fast = arr[fast] + 1;
	}

	return slow - 1;
}

int main()
{
	int arr[] = {0, 2, 1, 3, 5, 4, 6, 2};
	int n = 8;

	cout << repeat(arr, n);

	return 0;
}