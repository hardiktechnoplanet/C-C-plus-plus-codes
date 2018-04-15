/*if the string is too long, it is not a good idea to traverse it twice, 
so instead only storing just counts of a char, we also store the index, and then traverse 
the hash table.*/
#include<bits/stdc++.h>
#include <string>

using namespace std;

void firstUniqueChar(string s)
{
	int len=s.length();
	
	//multiset can have same values
	unordered_map <int, int> m;
	unordered_map <int, int> :: iterator it;
	
	for(int i=0;i<len;i++)
	{
		//store the index of non-duplicated numbers. 
		if(m.find(s[i])==m.end())
		{
			m[s[i]]=i;
		}
		//for duplicates, save the index as INT_MAX. 
		else
		{
			m[s[i]]=INT_MAX;
		}
	}
	
	int ans=INT_MAX;
	
	for(it=m.begin();it!=m.end();it++)
	{
		//get the minimum index
		ans = min(it->second, ans);
	}
	//first non repeating char is at 'ans' index in string s
	cout<<"first non repeating char in string is: "<<s[ans];
}
int main()
{
	string s="acbadcebh";
	firstUniqueChar(s);
	return 0;
}
