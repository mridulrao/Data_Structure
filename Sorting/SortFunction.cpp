/*  Inbuilt sort function 
Worst case and Average case : O(nlog(n))
Uses Intro Sort(hybrid of Quick Sort, Heap Sort, Insertion Sort)
*/

/*
// Sorting in array 

#include<iostream>
#include<algorithm>  // this library is used for specifying range of like array or stl container 

using namespace std;

int main()
{
	int arr[] = {10, 20, 5, 7};
	int n = sizeof(arr)/sizeof(arr[0]);

	sort (arr, arr + n); //algorithm library to give range of elements 

	for(int x: arr) // Range based for loop, usaully used for STL containers 
		cout << x << " ";

	sort(arr, arr + n, greater<int>()); //gretaer will store the array in reverse order 

	cout << endl;

	for(int x: arr)
		cout << x << " ";

	return 0;
}
*/


/*
// Sorting in vector 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> v = {10, 20, 5, 7};

	sort(v.begin(), v.end());

	for(int x: v)
		cout << x << " ";

	sort(v.begin(), v.end(), greater<int>());

	cout << endl;

	for(int x: v)
		cout << x << " ";

	return 0;
}
*/

// Custom function passing in sort

#include<iostream>
#include<algorithm>

using namespace std;

struct Point
{
	int x, y;
};

bool MyComp(Point p1, Point p2)
{
	return p1.x < p2.x;  // will sort the 2d array on bases of x cordinate of the points 
}

int main()
{
	Point arr[] = {{3, 10}, {2, 8}, {5, 4}};

	int n = sizeof(arr)/sizeof(arr[0]);

	sort(arr, arr + n, MyComp);

	for(auto i: arr)  // Range based for loop, usaully used for STL containers 
		cout << i.x << " " << i.y << endl;

	return 0;
}