#include<bits/stdc++.h>
#include <iostream>
using namespace std;
// Remove Duplicates From Sorted Array
/*Given a sorted array, remove the duplicates in-place such that each element appear 
only once and return the new length.cDo not allocate extra space for another array, 
you must do this by modifying the input array in-place with O(1) extra memory.*/
int removeDuplicate(int arr[],int len)
{
	/*Test Case: if array is empty*/
	if(len==0)
	{
		return 0;
	}
	int temp=0;
	for(int i=1;i<len;i++)
	{
		if(arr[i]!=arr[temp])
		{
			temp++;
			arr[temp]=arr[i];
		}
	}
	return temp+1;
}
int main()
{
	int arr[]={1,1,2};
	int len=sizeof(arr)/sizeof(arr[0]);
	cout<<"the length of the resultant array: "<<removeDuplicate(arr,len)<<endl;
	return 0;
}
