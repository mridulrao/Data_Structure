/* 
In CPP the matirx is stroed in row mager 
While passing the matirx the first dimension can be skipped 
rest of the dimensions need to be present 

Generally the element are stored in continous memeory location but not necessary 
*/

// Simple matrix declaration 

/* the below two methods will store the array in stack
Stack is used for static memory location */


#include<iostream>
using namespace std;

int main()
{
	//stored in stack 
	int arr[3][2] = {{10, 20},
					 {30, 40},
					 {50, 60}}	

	for(int i = 0;i < 3;i++)
		for(int j = 0;j < 2; j++)
			cout << arr[i][j] << " ";

	return 0;
}


// Variable sized array

#include<iostream>

using namespace std;

int main()
{
	int m = 3, n =2;
	int arr[m][n]

	for(int i = 0;i < m;i++)
		for(int j = 0;j < n;j++)
			cin >> arr[i][j];

	for(int i = 0;i < m;i++)
		for(int j = 0;j < n;j++)for(int i = 0;i < m;i++)
		for(int j = 0;j < n;j++)
			cin >> arr[i][j];
			cout << arr[i][j] << " ";

	return 0;
}

// The above two method are cache freindly as the data of the array 
//is stored in continous memmory location

//these method are not cache freindly as pointer can store the elemnt 
//at any empty memory space, not necessarly continous 


/* the methods below are based on dynamic memory allocatio 
so instead of stack(used for static memory), heap will be used for storing data
*/

//Using double pointer 

#include<iostream>

using namespace std;

int main()
{
	int m = 3, n =2;
	int **arr; //create a double pointer 

	arr = new int*[m]; // will create rows 

	for(int i = 0; i < m; i++)
		arr[i] = new int[n]; // will create column of size n

	/* if we use i instead of n --
		arr[i] = new int[i], then the number of columns in each row will 
		be differnet. First row will one column, next two, next three and so on.
		*/

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			arr[i][j] = 10;	

			cout << arr[i][j] << " ";
		}
	}


	return 0;
}

// Using array of pointer 

#include<iostream>

using namespace std;

int main()
{
	int m = 3, n = 2;

	int *arr[m]; //declare array of pointer, will represent rows 

	for(int i = 0; i < m; i++)
		arr[i] = new int[n]; // create n size column in each row 

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			arr[i][j] = 10;	

			cout << arr[i][j] << " ";
		}
	}


	return 0;
}



//Using arrays of vector 

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int m = 3, n =2;

	vector<int> arr[m]; //declare rows
	//here the number of rows is fixed

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n;j++)
			arr[i].push_back(10); //creating column by pushing elements


	// Print the vector
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			arr[i][j] = 10;	

			cout << arr[i][j] << " ";
		}
	}


	return 0;
}


//Using vectors of vectors
//here the number of rows are dynamic along with number of columns 

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int m = 3, n = 2;

	vector<vector<int>> arr;

	for(int i = 0; i < m; i++)
	{
		vector<int>v ; //create a vector which will store all
		//elements in one row 

		for(int j = 0; j < n; j++)
			v.push_back(10);

		//push the created vector in the original vector 
		//this will rrepresent complete row 
		arr.push_back(v);
	}

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			arr[i][j] = 10;	

			cout << arr[i][j] << " ";
		}
	}


	return 0;
}