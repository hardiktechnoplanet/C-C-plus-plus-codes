#include<bits/stdc++.h>
#include <iostream>
using namespace std;
//this code reverses the digits of an integer
int reverseDigit(int num)
{
	// handling negative numbers
	bool negativeFlag=0;
	if(num<0)
	{
		negativeFlag=1;
		num=-num;
	}
	int previous_num=0,reverse_num=0;
	while(num>0)
	{
		int current_digit=num%10;
		reverse_num=reverse_num*10+current_digit;
		//check for overflow
		if((reverse_num-current_digit)/10!=previous_num)
		{
			cout<<"Warning: overflow"<<endl;
			return 0;
		}
		previous_num=reverse_num;
		num=num/10;
	}
	return (negativeFlag==true)? -reverse_num : reverse_num;
	}
int main()
{
	int x=24;
	printf("%d",reverseDigit(x));
	return 0;
}
