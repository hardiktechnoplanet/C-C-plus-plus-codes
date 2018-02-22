#include<bits/stdc++.h>
#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
/*
bool isNumericChar(int x)
{
	if((x>='0')&&(x<='9'))
	return true;
	else
	return false;
}*/
int myAtoi(char *str)
{
	// check for null string
	if(*str==NULL)
	{
		return 0;
	}
	int res=0,sign=1,i=0;
	//check for negative number, if number is negative, sign=-1 and i++
	/*if(str[0]=='-')
	{
		sign=-1;
		i++;
	}*/
	while(str[i]<'0' || str[i]>'9')
	{
		i++;
	}
	for(;str[i]!='\0';i++)
	{
	/*	if(isNumericChar(str[i])==false)
		{
			return 0;
		}
	*/	res=res*10+str[i]-'0'; //ascii of 0 is 48, we have increase
		                       //the no by 48 so we have to subtract it 
	}
	return res;
	//return sign*res;
}
int main()
{
	char str[]="+";
	int val=myAtoi(str);
	printf("%d",val);
	return 0;
}
