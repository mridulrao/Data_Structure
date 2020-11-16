/* In this we use unordered_set which is implemented using 
hash tables where keys are hashed into indices of hash tables
so that the insertion is randomized.

geeks for geeks - https://www.geeksforgeeks.org/unordered_set-in-cpp-stl/

*/

//Find pair in unsorted array which gives desired sum

#include<bits/stdc++.h>
using namespace std;

void printPairs(int arr[], int arr_size, int sum)
{
	unordered_set<int> s;

	for(int i = 0; i < arr_size; i++)
	{
		int temp = sum - arr[i];

		if(s.find(temp) != s.end())
			cout << "Pair with given sum " << sum << " is(" << arr[i] << ", " << temp << ")" << endl;

			s.insert(arr[i]); 
	}
}

int main()
{
	int size;
	cout << "Enter the number of elements in array ";
	cin >> size;

	int arr[size];

	for(int i = 0;i < size; i++)
		cin >> arr[i];

	int sum;
	cout << "Enter the sum you want to calculate ";
	cin >> sum;

	printPairs(arr, size, sum);

	return 0;
}