#include<bits/stdc++.h>
using namespace std;
const int MAX = 100; //to specify the column size of the matrix 


//this function does binary search on the rows that are passed by 
// the searchmatrix function.
void binarySearch(int mat[][MAX], int i, int j_low, int j_high, int x)
{
    while(j_low <= j_high)
    {
        int j_mid = (j_low+j_high)/2;

        if(mat[i][j_mid] == x)
        {
            cout << "Element found at " << i << ", " << j_mid << endl;
            return;
        }

        else if(mat[i][j_mid] > x)
            j_high = j_mid - 1;

        else 
            j_low = j_mid + 1;
    }
    cout << "Element not found" << endl;
}

void sortedMatrixSearch(int mat[][MAX], int n, int m, int x)
{
    //if it is single row matrix 
    if(n == 1)
    {
        binarySearch(mat, 0, 0, m-1, x);
    }

    //Do binary search in middle column to minimise the number of 
    //rows for traversing. Terminate the loop when we find 2 possible 
    //rows which can have the key 

    int i_low = 0;
    int i_high = n-1;
    int j_mid = m/2; //the middle column
    while((i_low+1) < i_high) //this will stop when we find two rows 
    {
        int i_mid = (i_low + i_high)/2;

        //if element is found
        if(mat[i_mid][j_mid] == x)
        {cout << "Element found at " << i_mid << ", " << j_mid << endl;
            cout << "Element found at " << i_mid << ", " << j_mid << endl;
            return; 
        }

        else if(mat[i_mid][j_mid] > x)
            i_high = i_mid;

        else 
            i_low = i_mid;
    }

    // if element is present on the mid of two rows 
    if(mat[i_low][j_mid] == x)
        cout << "Element found at " << i_low << ", " << j_mid << endl;

    else if (mat[i_low+1][j_mid] == x)
        cout << "Element found at " << (i_low+1) << ", " << j_mid << endl;

    //Search element on 1st half of the 1st row 
    else if(x <= mat[i_low][j_mid-1])
        binarySearch(mat, i_low, 0, j_mid-1, x);
    //Search element on 2nd half of 1st row 
    else if(x >= mat[i_low][j_mid+1] && x <= mat[i_low][m-1])
        binarySearch(mat, i_low, j_mid+1, m-1, x);

    //Search element on 1st half of 2nd row
    else if(x <= mat[i_low+1][j_mid-1])
        binarySearch(mat, i_low+1, 0, j_mid-1, x);
    //Search elemnt on 2nd half of 2nd row 
    else
        binarySearch(mat, i_low+1, j_mid+1, m-1, x);
}

int main()
{
    // n is number of row
    // m is number of column
    int n = 4, m = 5, key = 8;
    int mat[][MAX] = {{0, 6, 8, 9, 11},
                      {20, 22, 28, 29, 31},
                      {36, 38, 50, 61, 63},
                      {64, 66, 100, 122, 128}};

    sortedMatrixSearch(mat, n, m, key);
    return 0;
}