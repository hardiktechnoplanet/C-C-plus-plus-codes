#include<bits/stdc++.h>

using namespace std;
//iterative method O(n)
/*
bool search (vector<int>& arr, int target)
{
	int n=arr.size();
	//test case
	if(n==0)
	return false;
	
	for(int i=0;i<n;i++)
	{
		if(target==arr[i])
		return true;
	}
	return false;
}
*/
//binary search O(logn)
bool search(vector<int>& arr, int target)
{
	int n=arr.size();
	if(n==0)
	{
		return 0;
	}
	int left=0, right=n-1;
	
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(arr[mid]==target)
		return true;
		
		//mid is the pivot
		//mid is the pivot implies it the largers element in the array
		else if(arr[mid]>arr[right])
		{
			if(arr[left]<=target && arr[mid]>=target)
			right=mid-1;
			else
			left=mid+1;
		}
		
		else if(arr[mid]<arr[right])
		{
			if(arr[mid]<=target && arr[right]>=target)
			left=mid+1;
			else
			right=mid-1;
		}
		else
		right--;
	}
	return false;
}
int main()
{
	vector<int> arr;
	arr.push_back(2);
	arr.push_back(5);
	arr.push_back(6);
	arr.push_back(0);
	arr.push_back(0);
	arr.push_back(1);
	
	if(search(arr,3)==true)
	{
		cout<<"target is present in the vector"<<endl;
	}
	else
	{
		cout<<"target is not present in the vector"<<endl;
	}

	return 0;
}
