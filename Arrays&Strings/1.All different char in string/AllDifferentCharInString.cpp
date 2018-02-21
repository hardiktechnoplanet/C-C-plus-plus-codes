#include<bits/stdc++.h>
#include <iostream>
//#include <ctype.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool unique(char string[],int len)
{
	int i=0;
	int array[256]={0};
	for (i=0;i<len;i++)
	{
	if(array[(string[i])]==0) //we need to convert char to ASCII
	array[(string[i])]=1;
	else 
	return false;
}
return true;
}
int main(int argc, char** argv) {
	char string[]="hmn";
	//int array[120]={0};

	int len=strlen(string);
	cout<<"len: "<<len<<endl;
	if(unique(string,len)==true)
	{
		cout<<"yes";
	}
	else
	cout<<"no";
	return 0;
}
