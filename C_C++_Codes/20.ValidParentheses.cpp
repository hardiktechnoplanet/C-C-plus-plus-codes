#include<bits/stdc++.h>
#include <iostream>
#include <string.h>
# include <stdlib.h>
#include <vector>
/*Problem Statement: Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid. The brackets must close in the correct order, "()" and "()[]{}" 
are all valid but "(]" and "([)]" are not.*/

using namespace std;
bool isValid(string s)
{
	//using stack (container adapters)
	stack <char> g;
	for(char c : s)
	{
		if(c=='(' || c=='{' || c=='[')
		{
			g.push(c);
		}
		else
		{
			if(g.empty())
			return false;
			if(c==')' && g.top()!='(')
			return false;
			if(c=='}' && g.top()!='{')
			return false;
			if(c==']' && g.top()!='[')
			return false;
			g.pop();
		}
	}
	return g.empty();

}
int main()
{
	string s="()[]";
	if(isValid(s)==true)
	printf("valid");
	else
	printf("invalid");
	return 0;
}
