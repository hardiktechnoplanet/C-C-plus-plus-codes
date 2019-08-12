#include<bits/stdc++.h>
#include <iostream>
#include <unordered_map> 
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int firstUniqChar(string s) {
        
        //first pass: insert all the chars in a map
        //second pass: check if the char is unique
        
        unordered_map<char,int> seen;
        unordered_map<char,int>::iterator it;
        
        //first pass
        for(size_t i=0;i<s.length();++i)
        {
            if(seen.find(s[i])==seen.end())
            {
                //cout<<"s[i]: "<<s[i]<<endl;
                seen.insert(pair <char,int> (s[i],1));
            }
            else
            {
                seen[s[i]]++;
            }
        }
        
        
        for(size_t i=0;i<s.length();++i)
        {
            cout<<"element: "<<seen[s[i]]<<endl;
            if(seen[s[i]]==1)
            {
                return i;
            }
        }
        return -1;
        
        
    }
int main(int argc, char** argv) {
	string s="leetcode";
	cout<<"ans: "<<firstUniqChar(s);
	return 0;
}
