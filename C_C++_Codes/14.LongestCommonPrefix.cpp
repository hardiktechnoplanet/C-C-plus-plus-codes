#include<bits/stdc++.h>
#include <iostream>
#include <string.h>
# include <stdlib.h>
using namespace std;
bool isCommonPrefix(vector <string>& s, int len)
{
	string str1=s[0].substr(0,len);
	for(int i=1;i<s.size();i++)
	{
		if(s[i].compare(0, str1.size(), str1))
		return false;
	}
	return true;
}
string longestPrefix(vector <string>& s)
{
	int s_size=s.size();
	cout<<"size: "<<s_size<<endl;
	if(s.empty() || s_size==0)
	{
		return "";
	}
	int minLen=INT_MAX;
	for(size_t i=0;i<input.size();++i)
	{
		string t=input[i];
		if(t.size()<minLen)
		minLen=t.size();
		t.clear();
	}

	cout<<"minLen: "<<minLen<<endl;
	int low=1;
	int high=minLen;
	while(low<=high)
	{
		int middle=(low+high)/2;
		if(isCommonPrefix(s,middle))
		low=middle+1;
		else
		high=middle-1;
	}
	return s[0].substr(0,((low+high)/2));
}
int main()
{
	vector <string> s;//= "leets", "leetcode","leetc","leeds";
	s.push_back("lee");
    s.push_back("leetcode");
    s.push_back("leetc");
    s.push_back("leeds");
    s.push_back("leedr");
    s.push_back("leedrwer");
	//vector <string> s= {"abca","abc"};
	cout<<longestPrefix( s);
	return 0;
}
