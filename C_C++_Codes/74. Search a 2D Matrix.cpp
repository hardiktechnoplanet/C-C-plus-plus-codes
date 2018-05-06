#include<bits/stdc++.h>
#include <iostream>
#define r 3
#define c 3
using namespace std;

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
