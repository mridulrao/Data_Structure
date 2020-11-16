// Square root of a number using binary search 

// cpp comes with inbuilt function of calculating square root (sqrt function) but its complexity is same as of naive method.

/* Naive method -- 
Time Complexity - O(n^1/2)

#include<iostream>
using namespace std;

int sqRootFloor(int x) //if the number do not have a perfect sqaure root then we store the floor value of nearest square root
{
	int i = 1;

	while(i*i <= x)
		i++;

	return (i - 1);
}

int main()
{
	int num;
	cin >> num;

	cout << sqRootFloor(num);

	return 0;
}

*/

/* above method but with binary search
Time complexity - O(log(n)) (faster than above method)

*/

#include<iostream>
using namespace std;

int sqRootFloor(int x)
{
	int low = 1, high = x, ans = -1; //ans will store the square root of number

	while(low <= high) //binary search
	{
		int mid = (low + high)/2;

		int mSq = mid*mid; //if this value is same as of x means this is the square root

		if(mSq == x)
			return mid;

		else if(mSq > x)
			high = mid - 1; //we have to decrease high cause the square root will be less than mid 

		else // if (mSq < x), but htis condition is not enough, we have to check for next value of mSq because it can also be less than x
		{
			low = mid + 1;
			ans = mid;
		}
	}
	return ans;
}

int main()
{
	int num;
	cin >> num;

	cout << sqRootFloor(num);

	return 0;	
}
