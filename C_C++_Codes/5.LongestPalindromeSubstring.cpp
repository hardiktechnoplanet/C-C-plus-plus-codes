#include<bits/stdc++.h>
#include <iostream>
using namespace std;
// this function will print the largest substring palindrome
void printSubstring(char *str,int start, int end)
{
	cout<<"the palindrome substring is: ";
	for(int i=start;i<=end;i++)
	cout<<str[i]<<endl;
}
int SubString(char *str,int len)
{
	int l=0, start=0,end=0, temp=1;
	int r=len-1-1;
	cout<<"value of r: "<<r<<endl;
	int count=0;
	cout<<"l: "<<str[l]<<endl;
	cout<<"r: "<<str[r]<<endl;
	while(l<r)
	{
		if(str[l]!=str[r])
		{
			l++;
			count=0; //if the characters do not match then we will make count=0
			temp=1;
		}
		else if(str[l]==str[r])
		{
			//temp is required to make sure that the start and end varialbes update
			//only once. Otherwise we will have the last value of l and r in start
			//and end
			if(temp==1)
			{
				start=l;
				end=r;
				temp++;
			}
			l++;
			r--;
			count++;
			
		}
	}
	//value of start and end is passed to the print function
	printSubstring(str,start,end);
	return count*2;
}
int main()
{
	char str[]="abcabbac";
	int len=sizeof(str)/sizeof(str[0]);
	cout<<len;
	cout<<"count: "<<SubString(str,len)<<endl;
	return 0;
}
