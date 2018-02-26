#include<bits/stdc++.h>
#include <iostream>
using namespace std;
// REMOVE ELEMENT
/*Given an array and a value, remove all instances of that value in-place and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.*/
int RemoveElement(int* arr, int numsSize, int n) {
    
    int temp=0;
	for(int i=0;i<numsSize;i++)
	{
		if(arr[i]!=n)
		{
			arr[temp]=arr[i];
            temp++;
		}
	}
	for(int i=0;i<temp;i++)
	cout<<arr[i]<<endl;
	return temp;    
}
int main()
{
	int arr[]={1,2,3,4};
	int len=sizeof(arr)/sizeof(arr[0]);
	int n=1;
	cout<<"the length of resultant array is: "<<RemoveElement(arr,len,n);
	return 0;
}
