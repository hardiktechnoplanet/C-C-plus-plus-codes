#include<bits/stdc++.h>
#include <iostream>
using namespace std;
/*There are 2 functions in the code. Run any one of them at 
a time. First function 'isPalindromeI' do not use any extra
space while the second function 'isPalindrome' uses an extra
array*/

bool isPalindromeI(int x)
{
	//Test Case1: if the number is negative
	//negative number can not be palindrome
	if(x<0)
	{
		return false;
	}
	//Test Case2: if the last digit of x is 0
	//the first digit or x should be 0
	if(x%10==0 && x!=0)
	{
		return false;
	}
	//Test Case3: positive number
	//To check the overflow condition, let us reverse only half of the
	//number. How to check if we have reached to the half of the number?
	//We are dividing the number by 10, and multiplying the reversed number by 10.
	//So, when the original number is less than the reversed number, it means 
	//we have processed half of the number digits.
	
	int reversedNumber=0;
	while(x>reversedNumber)
	{
		reversedNumber=reversedNumber*10 + x%10;
		x=x/10;
	}
	//in case of odd digit number, we can remove the middile digit as 
	//it will be comapred to itself to check if palindrome. Ex: 12321
	//hece, we can use reversedNumber/10
	if(x==reversedNumber || x==reversedNumber/10)
	return true;
	else 
	return false;
}
/*
bool isPalindrome(int x)
{
	int array[256]={0};
	int i=0;
	int sign=-1;
	//Test Case1: if number is0
	if(x==0)
	{
		return true;
	}
	//Test Case2: if number is negative
	//return false
	if(x<0)
	{
		return false;
	}
	//Test Case3: positive number
	//divide and save the every digit of the integer
	//in the array
	int reverse_num=0,previous_num=0;
	while(x%10>=1)
	{
		int current_digit=x%10;
		reverse_num=reverse_num*10+current_digit;
	/////check for overflow///////////////////////////////////////
		if((reverse_num-current_digit)/10!=previous_num)
		{
			cout<<"Warning: overflow"<<endl;
			return false;
		}
		previous_num=reverse_num;
	///////////////////////////////////////////////////////////////	
		array[i]=current_digit;
		cout<<array[i]<<endl;
		x=x/10;
		i++;
	}
	cout<<"i: "<<i<<endl;
	int l=0;
	int r=i-1;
	//compare the array elements, last element should be
	//equal to first and second last should be equal to second
	//and go on
	while(l<r)
	{
		if(array[l]==array[r])
		{
			l++;
			r--;
		}
		else
		return false;
	}
	return true;
}*/
int main()
{
	int x=12321;
	//if(isPalindrome(x)==true)
	if(isPalindromeI(x)==true)
	cout<<"yes the number is palindrome";
	else
	cout<<"number is not palindrome";
	return 0;
}
