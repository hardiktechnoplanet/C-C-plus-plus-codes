#include<bits/stdc++.h>
#include <iostream>
#include <string.h>
# include <stdlib.h>
#include <vector>
#include <math.h>
/*problem statement: Given an array S of n integers, find three integers in S such that 
the sum is closest to a given number, target. Return the sum of the three integers. 
You may assume that each input would have exactly one solution.*/4
/*there are 2 implementations in the code below, use any one function and comment the other
one function uses array and the other uses STL container: vector*/
using namespace std;
int threeSumClosest(vector<int>& nums, int target) 
{
	//sort the array
	sort(nums.begin(),nums.end());
	//if there are <3 elements in the array, return 0
	if(nums.size()<3)
	return 0;
	int numsSize=nums.size();
	int sum=nums[0]+nums[1]+nums[2];
	int present_sum=0;
	for(int i=0;i<numsSize-2;i++)
	{
		int a=nums[i];
		int l=i+1;
		int r=numsSize-1;
		while (l<r)
		{
			present_sum=a+nums[l]+nums[r];
			if(abs(target-sum)>abs(target-present_sum))
			{
				sum=present_sum;
				if(sum==target)
				{
				printf("sum: %d\n",sum);
				return sum;
			}	
			}
			if(present_sum>target)
			{
				r--;
			}
			else
			{
				l++;
			}
		}
		
	}
	printf("\nclosest value: %d\n",sum);
	return sum;	
}
/*
int threeSumCloset(int* nums,int numsSize,int target)
{
	//sort the array
	for(int i=0;i<numsSize;i++)
	{
		for(int j=i+1;j<numsSize;j++)
		{
			if(nums[i]>nums[j])
			{
				int temp=nums[j];
				nums[j]=nums[i];
				nums[i]=temp;
			}
		}
	}
	//print the sorted array
	for(int i=0;i<numsSize;i++)
	{
		printf("%d\t\n",nums[i]);
	}
	//fix a, update b and c 
		
	int sum=nums[0]+nums[1]+nums[2];
	int present_sum=0;
	for(int i=0;i<numsSize-2;i++)
	{
		int a=nums[i];
		int l=i+1;
		int r=numsSize-1;
		while (l<r)
		{
			present_sum=a+nums[l]+nums[r];
			if(abs(target-sum)>abs(target-present_sum))
			{
				sum=present_sum;
				if(sum==target)
				{
				printf("sum: %d\n",sum);
				return sum;
			}	
			}
			if(present_sum>target)
			{
				r--;
			}
			else
			{
				l++;
			}
		}
		
	}
	printf("\nclosest value: %d\n",sum);
	return sum;

}*/
int main()
{
	vector <int> nums={-1,0,1,2,-1,-4};
	/*int nums[]={1,2,4,5};
	int numsSize=sizeof(nums)/sizeof(nums[0]);
	int target=12;
    int sum=threeSumCloset(nums,numsSize,target);*/
    int target=4;
    int sum=threeSumClosest(nums,target);
	printf("closest sum is: %d\n",sum);
	return 0;
}
