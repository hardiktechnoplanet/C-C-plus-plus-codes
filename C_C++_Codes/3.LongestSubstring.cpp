#include<bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;
int lengthOfLongestSubstring(string s)
{
	/*If we want to use vector then uncomment the commented code and commen the hashset
	code*/
	/*
	vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        //cout<<"ff: "<<dict[s[0]]<<endl;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
            {
			    start = dict[s[i]];
			    
		}
		cout<<"ff: "<<dict[s[i]]<<endl;
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
	*/
	
	//creat a hashset
	set <char> arr;
	int n=s.length();
	int i=0,j=0,ans=0;
	cout<<"size: "<<n<<endl;
	/*HashSet is used to store the characters in current window [i, j) where (j = i initially). 
	Slide the index j to the right. If the element is not in the HashSet, slide j further. 
	Repeat the process until s[j] is already in the HashSet. At this point, we found the maximum size of 
	substrings without duplicate characters start with index i. Doing this for all i, gives the answer.*/
	while(i<n && j<n)
	{
		if(arr.find(s[j])==arr.end())
		{
			arr.insert(s[j++]);
			ans=max(ans,j-i);
			cout<<"j:"<<j<<"\ti: "<<i<<"\ts[j-1]: "<<s[j-1]<<endl;
			//cout<<"i: "<<i<<endl;
		}
		else
		{
			arr.erase(s[i++]);
			//cout<<"hello: "<<i<<endl;
			//cout<<"hello again: "<<j<<endl;
			cout<<"hello"<<"j:"<<j<<"\ti: "<<i<<"\ts[j]: "<<s[j]<<endl;
		}
	}
	cout<<"ans: "<<ans;
	return ans;
}
int main()
{
	//char s[]="pwwkew";
	//int len=sizeof(s)/sizeof(s[0]);
	string s="dvdf";
	cout<<"length of longest non repeating substing: "<<lengthOfLongestSubstring(s);
	return 0;
}
