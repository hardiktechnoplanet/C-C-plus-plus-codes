/*Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word in the string.
If the last word does not exist, return 0.*/

#include<bits/stdc++.h>
using namespace std;

int LengthOfLastWord(string s)
{
	int len=s.length();
	
	//test case: if string is empty
	if(len==0)
	{
		return 0;
	}
	int ptr=len-1;
	cout<<s[ptr];
	int count=0;
	
	//test case: if last word is blank, ex string="a "
	while(s[ptr]==' ')
	{
		ptr--;
	}
	
	//decrement the pointer while we encounter space (space indicates start of 
	//new word)
	while(s[ptr]!=' ' && ptr>=0)
	{
		count++;
		ptr--;
	}
	return count;
}
int main()
{
	string s=" ";
	cout<<"length of last word: "<<LengthOfLastWord(s)<<endl;
}
