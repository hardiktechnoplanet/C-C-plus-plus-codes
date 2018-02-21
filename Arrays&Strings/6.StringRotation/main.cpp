#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include<stdio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*this code checks if string 2 is rotation of string 1?*/
bool isRotation(string str1,string str2,int len1,int len2)
{
	int count=0;
	int j=0;
	cout<<"len1: "<<len1<<endl;
	cout<<"len2: "<<len2<<endl;
	if(len1!=len2)
	{
		return false;
	}
	//string concatenation
	string s1=str1;
	str1 =str1 + s1;
	//cout<<str1<<e;
	int newLen=str1.length();
	cout<<newLen<<endl;
	for(int i=0;i<newLen;i++)
	{
		if(str1[i]==str2[j])
		{
			count++;
			j++;
			if(count==len2)
			{
				return true;
			}
		}
		else{
		j=0;
		count=0;
	    }}
		
		
	
	return false;
	}
int main(int argc, char** argv) {
	string str1="hardiki";
	string str2="ikhard";
	int len1=str1.length();
	cout<<"length"<<len1<<endl;
	int len2=str2.length();
	if(isRotation(str1,str2,len1,len2)==true)
	cout<<"yes";
	else
	cout<<"no";
	return 0;
}
