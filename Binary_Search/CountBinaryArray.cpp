// to count the occurences of 1 in an binary array

#include<iostream>
using namespace std;

int countOnes(int arr[], int n)
{
	int low = 0, high = n - 1;

	while(low <= high)
	{
		int mid = (low + high)/2;

		if (arr[mid == 0]) //since this is sorted binary array all the frequency of 1 will be in right side of array
			low = mid + 1;

		else //if arr[mid] == 1
		{
			if(mid == 0 || arr[mid - 1] == 0)
				return (n - mid); // since after mid all elements will be 1
			else
				high = mid - 1; // if there is no frequency of 1 then to terminate loop we bring low and high closer to each other.
		}
	}

	return 0;
}

int main()
{
	int arr[] = {0, 0, 1, 1, 1, 1}, n = 6;

	cout << countOnes(arr, n);

	return 0;
}

