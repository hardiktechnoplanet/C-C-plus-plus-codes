#include<bits/stdc++.h>
#include <iostream>
#include <string.h>
# include <stdlib.h>
using namespace std;
void longestPrefix(string arr[],int len)
{
	int array[256]={0};
	int j=0;
	string common_string[10];
	string str1=arr[0];
	int len1=str1.length();
	string str2=arr[1];
	int len2=str2.length();
	for(int i=0;i<len1;i++)
	{
		array[str1[i]]++;
	}
	for(int i=0;i<len2;i++)
	{
		if(array[str2[i]]>0)
		{
			common_string[j++]=str2[i];
		}
	}
	cout<<"common prefix: ";
	for(int i=0;i<10;i++)
	{
		cout<<common_string[i]<<endl;
	}
//	cout<<'arr[0]'<<endl;
//	cout<<'arr[1]'<<endl;
}
int main()
{
	string arr[] = {"geeksforgeeks", "geeks"};
                    //"geek", "geezer"};
    int len=sizeof(arr)/sizeof(arr[0]);
    longestPrefix(arr,len);
	//cout<<len<<endl;
	return 0;
}
