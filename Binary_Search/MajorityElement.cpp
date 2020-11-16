/* Majority element is an element that apperas more than n/2 times in array
where n is the size of the array.

This algorithm is known as moore's voting algorithm, its time complexity is O(n)

the naive method of this problem has complexity of O(n^2) becuase it has two nested loops. 
*/


/* Naive method -

#include<iostream>
#include<cmath>

using namespace std;

int findMajority(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int count = 1;

		for(int j = i + 1; j < n; j++)
		{
			if(arr[i] == arr[j])
				count ++;
		}

		if(count > n/2)
			return i;
	}
	return -1;
}

int main()
{
	int arr[] = {8, 7, 6, 8, 6, 6, 6, 6}, n = 8;

	cout << findMajority(arr, n);

	return 0;	
}

*/

//Moore's voting algorithm 

#include<iostream>
#include<cmath>
using namespace std;

int findMajority(int arr[], int n)
{
	int res = 0, count = 1;
	 for(int i = 1; i < n; i++)
	 {
	 	if(arr[res] == arr[i])
	 		count ++;
	 	else
	 		count --;
	 	if(count == 0)
	 	{
	 		res = i;
	 		count  = 1;
	 	}
	 }

	 count = 0;

	 for(int i = 0; i < n;i++)
	 	if(arr[res] == arr[i])
	 		count++;

	 if(count <= n/2)
	 	res = -1;

	 return res;
}

int main()
{
	int arr[] = {8, 8, 6, 6, 6, 4, 6}, n = 7;

	cout << findMajority(arr, n);

	return 0;
}
