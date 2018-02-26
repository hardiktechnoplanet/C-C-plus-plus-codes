#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;
// GENERATE PARENTHESES
//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
void _generateParenthesis(int position,int n, int open,int close);
void generateParenthesis(int n)
{
	if(n>0)
	_generateParenthesis(0,n,0,0);
	return;
}
void _generateParenthesis(int position,int n, int open,int close)
{
	static char str[MAX];
	//static vector <char> str;
	//vector <int> :: const_iterator i;
	if(close==n)
	{
		//for(auto i=str.begin();i!=str.end();++i)
		//cout<<*i<<endl;
		cout<<str<<endl;
		return;
	}
	else
	{
		if(open<n)
		{
			str[position]='{';
			//str.push_back('{');
			_generateParenthesis(position+1,n,open+1,close);
		}
		if(open>close)
		{
			//str.push_back('}');
			str[position]='}';
			_generateParenthesis(position+1,n,open,close+1);
		}
	}
}
int main()
{
	int n=2;
	generateParenthesis(n);
	return 0;
}
