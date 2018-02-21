#include<bits/stdc++.h>
#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool anagram(char str1[],char str2[],int len1,int len2)
{
	int array[256]={0};
	int flag=1;
	int i;
	if(len1!=len2)
	{
		return false;
	}
	
	for(i=0;i<len1;i++)
	{
		array[toascii(str1[i])]=1;
	}
	for(i=0;i<len2;i++)
	{
		if(array[toascii(str2[i])]!=1)
		{
		  return false;
		}
	}
	return true;
}
int main(int argc, char** argv) {
	char str1[]="hardik";
	char str2[]="kartik";
	int len1=sizeof(str1);
	int len2=sizeof(str2);
	if(anagram(str1,str2,len1,len2)==true)
	{
		cout<<"yes";
	}
	else
	cout<<"no";
	return 0;
}
