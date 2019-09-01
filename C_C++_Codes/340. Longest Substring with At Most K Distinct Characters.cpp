class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        int start=0,end=0,maxLen=0;
        unordered_map<char,int> dict;
        
        while(end<s.length())
        {
            char c=s[end];
            //if this char is in dict, increase the frequency
            if(dict.find(c)!=dict.end())
            {
                dict[c]++;
            }
            //else add it to the dict
            else
            {
                dict[c]=1;
            }
            //if the dict size is>k, we need to balance it
            while(dict.size()>k)
            {
                c=s[start];
                if(--dict[c]==0)
                {
                    dict.erase(c);
                }
                start++;
            }
            maxLen=max(maxLen,end-start+1);
            end++;
        }
        return maxLen;
        
    }
};
