#include<bits/stdc++.h>
#include <iostream>
#include <string.h>
# include <stdlib.h>
#include <vector>
/*Problem Statement: Given an array S of n integers, are there elements a, b, c in S 
such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.*/
/*there are 2 implementations in the code below, use any one function and comment the other
one function uses array and the other uses STL container: vector*/

using namespace std;
vector<vector<int> > threeSum(vector<int> &num) {
    
	vector<vector<int> > res;
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++) {
        
        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back) {

            int sum = num[front] + num[back];
            
            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);
                              
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) back--;
            }
            
        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;
    }
    return res;    
}
/*
void threeSum(int arr[],int len)
{
	bool found=false;
	bool duplicateFlag=false;
	int count=0;
	//Sort the array
	for(int i=0;i<len;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if(arr[i]>arr[j])
			{
				int temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
	for(int i=0;i<len;i++)
	{
		cout<<"\t"<<arr[i];
	}
	//We have the sorted array, we will fix a and try to find 
	// b and c
	int a=0;
	for(int i=0;i<len;i++)
	{
		count++;
		//to remove duplicate values of a,b, and c
		if(count>1)
		{
			if(a==arr[i])
			{
				duplicateFlag=true;
			}
		}
		if(duplicateFlag==true);
		else
		{
		a=arr[i];
		int l=i+1;
		int r=len-1;
		while(l<r)
		{
			if(a+arr[l]+arr[r]==0)
			{
				printf("\n");
				printf("%d %d %d\n",a,arr[l],arr[r]);
				l++;
				r--;
				found=true;
			}
			//if the sum is <0 then increment l
			else if(a+arr[l]+arr[r]<0)
			{
				l++;
			}
			//if the sum is >0 then decrement r
			else
			{
				r--;
			}
		}
	}}
	if(found==false)
	{
		cout<<"triplet not found"<<endl;
	}
}*/
int main()
{
	vector <int> num={-1,0,1,2,-1,-4};
	int arr[]={-1,0,1,2,-1,-4};
	int len=sizeof(arr)/sizeof(arr[0]);
    //threeSum(arr,len);
    vector<vector<int> > resres=threeSum(num);
    vector <int> :: iterator i;
    for(i=resres.begin();i!=resres.end();++i)
    cout<<*i;
    //cout<<result<<endl;
	//cout<<len<<endl;
	return 0;
}
