/*A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach 
the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?*/

#include<bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

//function using recursion, this is not efficient solution as it repeating same calculations
/*
// Returns count of possible paths to reach cell at row number m and column
// number n from the topmost leftmost cell (cell at 1, 1)
int  numberOfPaths(int m, int n)
{
   // If either given row number is first or given column number is first
   if (m == 1 || n == 1)
        return 1;
 
   // If diagonal movements are allowed then the last addition
   // is required.
   return  numberOfPaths(m-1, n) + numberOfPaths(m, n-1);
           // + numberOfPaths(m-1,n-1);
}
*/

//there are 2 functions, use any one of them, first one uses 2D matrix and the
//second one used 2D vector.
 
/*
// Returns count of possible paths to reach cell at row number m and column
// number n from the topmost leftmost cell (cell at 1, 1)
int numberOfPaths(int m, int n)
{
    // Create a 2D table to store results of subproblems
    int count[m][n];
 
    // Count of paths to reach any cell in first column is 1
    for (int i = 0; i < m; i++)
        count[i][0] = 1;
 
    // Count of paths to reach any cell in first column is 1
    for (int j = 0; j < n; j++)
        count[0][j] = 1;
 
    // Calculate count of paths for other cells in bottom-up manner using
    // the recursive solution
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
 
            // By uncommenting the last part the code calculatest he total
            // possible paths if the diagonal Movements are allowed
            count[i][j] = count[i-1][j] + count[i][j-1]; //+ count[i-1][j-1];
 
    }
    return count[m-1][n-1];
}
*/
int uniquePath(int m,int n)
{
	//create a 2D vector to store the result
	//the first row and first column of the vector should be =1
	//because there 1 way to reach all those elements
	vector<vector<int>>path(m, vector<int>(n,1));        
    
	//construct rest of the vector
	for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            path[i][j]=path[i-1][j]+path[i][j-1];
        }
    }
    return path[m-1][n-1];
}
int main()
{
	int m=4;
	int n=4;
	cout<<uniquePath(m,n)<<endl;

}
