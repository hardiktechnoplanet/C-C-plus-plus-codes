/*Find the contiguous subarray within an array (containing at least one number) 
which has the largest sum.
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.*/

//the problem is solved using 2 functions, use any one of them. One function
//is the recursion function
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
/*
int contiguousArray(vector<int> &array)
{
	int n=array.size();
	int sum=0;
	int max_sum=array[0];
	
	for(int i=0;i<n;i++)
	{
		sum+=array[i];
		if(sum>max_sum)
		{
			max_sum=sum;
		}
		if(sum<0)
		{
			sum=0;
 		}
	}
	return max_sum;
}
*/

//Recursion
int maxSubArray(int* array, int n) {
    
	//base case
    if(n==1)
        {
            return array[0];
        }
        
		int m=n/2;
        int leftSubArray=maxSubArray(array,m);
        int rightSubArray=maxSubArray(array+m,n-m);
            
        int leftSum=INT_MIN, rightSum=INT_MIN, sum=0;
    
    for(int i=m;i<n;i++)
    {
        sum+=array[i];
        rightSum=max(sum,rightSum);
    }
    sum=0;
    for(int i=m-1;i>=0;i--)
    {
        sum+=array[i];
        leftSum=max(sum,leftSum);
    }
    int ans=max(leftSubArray,rightSubArray);
    return max(ans,leftSum+rightSum);
 
    
}
int main()
{
	/*vector <int> array;
	array.push_back(-2);
	array.push_back(1);
	array.push_back(-3);
	array.push_back(4);
	array.push_back(-1);
	array.push_back(2);
	array.push_back(1);
	array.push_back(5);  
	array.push_back(-5); 
	array.push_back(4);
	cout<<"max sum: "<<contiguousArray(array)<<endl;;
	*/
	int array[]={-2,1,-3,4,-1,2,1,5,-5,4};
	int n=sizeof(array)/sizeof(array[0]);
	cout<<"max sum: "<<maxSubArray(array,n);
	return 0;
}
