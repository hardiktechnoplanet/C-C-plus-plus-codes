#include<bits/stdc++.h>
#include <iostream>
using namespace std;
// GENERATE PARENTHESES
//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
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
