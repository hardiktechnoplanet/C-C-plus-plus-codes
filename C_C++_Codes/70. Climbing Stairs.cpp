#include<bits/stdc++.h>
using namespace std;

/*
int climbStairsHelper(int i,int n)
{
	//base cases:
	if(i>n)
	return 0;
	
	if(i==n)
	return 1;
	
	//recursion
	return climbStairsHelper(i+1,n) + climbStairsHelper(i+2,n);
}
int climbStairs(int n)
{
	return climbStairsHelper(0,n);
}
*/
/*In the previous approach we are redundantly calculating the result for every step. 
Instead, we can store the result at each step in an array and directly returning 
the result from the memo array whenever that function is called again.*/

//https://www.youtube.com/watch?v=NFJ3m9a1oJQ
//DP: Top-Down: both time and space complexity O(n)
/*class Solution {
public:
    int climbStairs(int n) 
    {
        if(n==0)
        {
            return 0;
        }
        vector<int> mem(n+1,-1);
        return helper(n,mem);
    }
    int helper(int n,vector<int>& mem)
    {
        if(n<0)
        {
            return 0;
        }
        else if(n==0)
        {
            return 1;
        }
        else if(mem[n]>-1)
        {
            return mem[n];
        }
        
        //recursion
        mem[n]=helper(n-1,mem)+helper(n-2,mem);
        return mem[n];
    }
};*/

//DP: Bottom Up approach
class Solution {
public:
    int climbStairs(int n) 
    {
        if(n==0)
        {
            return 0;
        }
        vector<int> T(n+1,0);
        
        //there is one way to go 0 steps
        T[0]=1;
        //there is one way to go 1 steps
        T[1]=1;
        
        for(size_t i=2;i<=n;++i)
        {
            // to go to ith step, we can either take 1 jump from i-1 step or 2 jumps from i-2 steps
            T[i]=T[i-1]+T[i-2];
        }
        return T[n];
    }
};
int climbStairs(int n)
{
	int mem[n+1]={0};
	return climbStairsHelper(0,n,memory);
}

int main()
{
	int x=5;
	cout<<"no of different ways: "<<climbStairs(x)<<endl;
}
