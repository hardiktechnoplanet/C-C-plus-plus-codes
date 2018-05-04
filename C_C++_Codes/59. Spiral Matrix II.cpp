#include <stdio.h>
#include<bits/stdc++.h>

using namespace std;

//use the below function if vector is to be used instead of array
/* 
vector<vector<int>> generateMatrix(int c) {
        
    vector<vector<int> > a( c, vector<int>(c) );
    //vector<vector<int>> a;
    //test case
    if(c==0)
    {
        return a;
    }
   
       // int a[c][c]={0};
    int n=c,m=c;
	int i, k = 0, l = 0,count=1;
 
    //  k - starting row index
    //    m - ending row index
    //    l - starting column index
    //    n - ending column index
     //   i - iterator
    
 
    while (k < m && l < n)
    {
        // Print the first row from the remaining rows 
        for (i = l; i < n; ++i)
        {
            a[k][i]=count++;
        }
        k++;
 
        // Print the last column from the remaining columns 
        for (i = k; i < m; ++i)
        {
            a[i][n-1]=count++;
        }
        n--;
 
        // Print the last row from the remaining rows 
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                a[m-1][i]=count++;
            }
            m--;
        }
 
        //Print the first column from the remaining columns 
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                a[i][l]=count++;
            }
            l++;    
        }        
    }
        return a;
        
    }
*/

void spiralMat(int c)
{
    //test case
    if(c==0)
    {
    	return;
	}
	int a[c][c];
    int n=c,m=c;
	int i, k = 0, l = 0,count=1;
 
    /*  k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
 
    while (k < m && l < n)
    {
        /* Print the first row from the remaining rows */
        for (i = l; i < n; ++i)
        {
            a[k][i]=count++;
        }
        k++;
 
        /* Print the last column from the remaining columns */
        for (i = k; i < m; ++i)
        {
            a[i][n-1]=count++;
        }
        n--;
 
        /* Print the last row from the remaining rows */
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                a[m-1][i]=count++;
            }
            m--;
        }
 
        /* Print the first column from the remaining columns */
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                a[i][l]=count++;
            }
            l++;    
        }        
    }
    //testing code
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cout<<a[i][j]<<"\t";
		}
	//	cout<<endl;
	}
	cout<<a[2][1]<<endl;
}
 
/* Driver program to test above functions */
int main()
{
	int n=3;
    spiralMat(n);
    return 0;
}

