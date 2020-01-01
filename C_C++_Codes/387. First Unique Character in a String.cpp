/*Solution 1: Two Pass (traverse through the string twice)
In the first pass fill the map and in the second pass find the 
first non repeating element.

If the string length is too long, it will not be effective to traverse through it
twice. The Solution 2 solves this problem*/

/*
class Solution {
public:
    int firstUniqChar(string s) {
        
        //first pass: insert all the chars in a map
        //second pass: check if the char is unique
        
        unordered_map<char,int> seen;
        
        //first pass
        for(size_t i=0;i<s.length();++i)
        {
            seen[s[i]]++;
        }
        
        for(size_t i=0;i<s.length();++i)
        {
            if(seen[s[i]]==1)
            {
                return i;
            }
        }
        return -1;
    }
};*/

//Solution 2
/*
class Solution {
public:
    int firstUniqChar(string s) {
        
        //first pass: insert all the chars in a map
        //second pass: check if the char is unique
        
        unordered_map<char,int> seen;
        int ans=INT_MAX;
        
        //first pass
        for(size_t i=0;i<s.length();++i)
        {
            if(seen.find(s[i])==seen.end())
                seen[s[i]]=i;
            else 
                seen[s[i]]=INT_MAX;
        }
        
        for(auto it:seen)
        {
            ans=min(ans,it.second);
        }
        if(ans==INT_MAX)
            return -1;
        else
            return ans;
    }
};*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> seen;
        int ans = s.size();
        
        for (int i = 0; i < s.size(); i++) 
        {
            seen[s[i]].first++;
            seen[s[i]].second = i;
        }
        for (auto it : seen) {
            if (it.second.first == 1) 
                ans = min(ans, it.second.second);
        }
        return ans == s.size() ? -1 : ans;
    }
};
