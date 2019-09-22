#include<bits/stdc++.h>
#include <iostream>
#define r 3
#define c 3
using namespace std;

// O(log(nm))   https://www.youtube.com/watch?v=FOa55B9Ikfg
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        //test case
        if(matrix.size()==0)
        {
            return false;
        }
        
        /*
        The left and right pointer to our search. We imagine a visualization
        of a 1D array and will use our mapping system to convert these indices
        into concrete locations in the 2D matrix.
        The the last position in the matrix if we consider it as array will be
        rows * cols - 1 indices.
        Same as an array...an array's last index is arr.length - 1.
      */
        
        int totalRows=matrix.size();
        int totalCols=matrix[0].size();
        
        int left=0, right=totalRows*totalCols-1;
        
         
        //Continue searching while the left has not passed the right
        while(left<=right)
        {
            //Prevent overflow, find the middle this 
            //way instead of doing: (right + left) / 2
            int mid=left+((right-left)/2);
            
            // We need to map from our conceptualized 1D 
            //array back to our 2D matrix to index into it.
            int midElementVal=matrix[mid/totalCols][mid%totalCols];
            
            if(midElementVal==target)
            {
                return true;
            }
            else if(midElementVal<target)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return false;
        
    }
};
/*
bool SearchMat(int mat[r][c],int m, int n,int target)
{
	int k=0; //starting index of row
	int l=0; //starting index of column
	
	//test case: if matrix size is zero
	if(m==0 || n==0)
	return false;
	
	while(k<=m-1)
	{
		for(int i=l; i<=n-1; i++)
		{
			if(mat[k][i]==target)
			return true;
		}
		k++;
	}
	return false;

}
*/
bool SearchMat(int mat[r][c],int m, int n,int target)
{
	int k=0; //starting index of row
	int l=0; //starting index of column
	
	//test case: if matrix size is zero
	if(m==0 || n==0)
	return false;
	
	while(k<=m-1)
	{
		int low=l;
        int high=n-1;
        if(target>=mat[k][l] && target<=mat[k][n-1])
		{
            while(low<=high)
            {
            	int mid=(low+high)/2;
            	cout<<"mid: "<<mid<<endl;
                if(mat[k][mid]>target)
                    high=mid-1;
                else if(mat[k][mid]<target)
                    low=mid+1;
                else
                    return true;
            }
		}
		else{
		cout<<"hello"<<endl;
		k++;}
	}
	return false;

}

int main()
{
    int mat[r][c] = { {1,  2,  3},
        {7,  8,  9},
        {13, 14, 15}
    };
    int target=15;
    if(SearchMat(mat,r,c,target)==true)
    {
    	cout<<"the target is present in the matrix"<<endl;
	}
	else
	{
		cout<<"the target is not present in the matrix"<<endl;
	}
	return 0;
}
