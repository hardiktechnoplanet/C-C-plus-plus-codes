//Given a collection of distinct numbers, return all possible permutations.
//https://www.youtube.com/watch?v=78t_yHuGg-0
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
void indent(int n)
{
	for(int i=0;i<n;i++)
	cout<<"....";
}
void permutationHelper(string s, string choosen)
{
	indent(choosen.length());
	cout<<"permutationHelper(\""  <<  s << "\",\"" << choosen << "\")" << endl;
	//Base case: if the string is empty, print the things we have choosen so far
	if(s.empty())
	{
		cout<<choosen<<endl;
	}
	else
	{
		//choose, explore, unchoose 
		
		/*pick one of the letter, explore what can come after, come back and 
		unpick that letter and try the next letter and repeat.*/
		for(int i=0;i<s.length();i++)
		{
			//choose
			char c=s[i];
			
			//for exploration, we need to add this 'c' to choosen and remove it from 's'.
			choosen +=c;
			s.erase(i,1); //at index i remove 1 character
			
			//explore what can come after that
			permutationHelper(s,choosen);
			
			//unchoose
			s.insert(i,1,c);
			choosen.erase(choosen.length()-1,1); //remove last character from choosen
		}
	}
}
void permutation(string s)
{
	permutationHelper(s,"");
}
int main()
{
	string s="ABC";
	permutation(s);
	return 0;
}
