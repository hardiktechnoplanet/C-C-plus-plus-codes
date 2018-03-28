//Given a collection of numbers that might contain duplicates, return all 
//possible unique permutations.
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
void indent(int n)
{
	for(int i=0;i<n;i++)
	cout<<"....";
}
void permutationHelper(string s, string choosen, set<string>& alreadyPrinted)
{
	indent(choosen.length());
	cout<<"permutationHelper(\""  <<  s << "\",\"" << choosen << "\")" << endl;
	//Base case: if the string is empty, print the things we have choosen so far
	if(s.empty())
	{
		if(alreadyPrinted.find(choosen)==alreadyPrinted.end())
		{
			cout<<choosen<<endl;
			alreadyPrinted.insert(choosen);
		}
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
			permutationHelper(s,choosen,alreadyPrinted);
			
			//unchoose
			s.insert(i,1,c);
			choosen.erase(choosen.length()-1,1); //remove last character from choosen
		}
	}
}
void permutation(string s)
{
	set<string> choosen; // to keep track of duplicates
	permutationHelper(s,"",choosen);
}
int main()
{
	string s="112";
	permutation(s);
	return 0;
}
