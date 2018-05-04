#include<bits/stdc++.h>
#include <iostream>
#include<stdio.h>
#define r 3
#define c 3
using namespace std;

void spiralMat(int mat[r][c],int m,int n)
{
	//test case
	if(mat==0)
	{
		return;
	}
	int *result = (int *)malloc(r * c * sizeof(int));
	int k=0; //starting index of row
	int l=0; //starting index of column
	int i,j=0;
	while(l<n && k<m)
	{
		//print the first row from the remaining rows
		for(i=l;i<n;i++)
		{
			result[j++]=mat[k][i];
		}
		k++;
		
		//print the last columns from the remaining columns
		for(i=k;i<m;i++)
		{
			result[j++]=mat[i][n-1];
		}
		n--;
		
		//print the last row from the remaining rows
		if(k<m)
		{
			for(i=n-1;i>=l;i--)
			{
				result[j++]=mat[m-1][i];
			}
			m--;
		}
		
		//print the first column from the remaining columns
		if(l<n)
		{
			for(i=m-1;i>=k;i--)
			{
				result[j++]=mat[i][l];
			}
			l++;
		}
	}
	int size=sizeof(result)/sizeof(result[0]);
	for(int i=0;i<size;i++)
	{
		cout<<result[i]<<"\t";
	}
	
	cout<<result[5];
}

//using vector
/*vector<int> spiralOrder(vector<vector<int>>& mat) {
        
        if(mat.empty())
        {
            return {};
        }
    vector<int> result;	
    int m=mat.size();
    int n=mat[0].size();
    int k=0; //starting index of row
	int l=0; //starting index of column
	int i;

	while(l<n && k<m)
	{
		//print the first row from the remaining rows
		for(i=l;i<n;i++)
		{
			result.push_back(mat[k][i]);
		}
		k++;
		
		//print the last columns from the remaining columns
		for(i=k;i<m;i++)
		{
			result.push_back(mat[i][n-1]);
		}
		n--;
		
		//print the last row from the remaining rows
		if(k<m)
		{
			for(i=n-1;i>=l;i--)
			{
				result.push_back(mat[m-1][i]);
			}
			m--;
		}
		
		//print the first column from the remaining columns
		if(l<n)
		{
			for(i=m-1;i>=k;i--)
			{
				result.push_back(mat[i][l]);
			}
			l++;
		}
	}
        return result;
}*/

int main()
{
    int mat[r][c] = { {1,  2,  3},
        {7,  8,  9},
        {13, 14, 15}
    };
    spiralMat(mat,r,c);
	return 0;
}
