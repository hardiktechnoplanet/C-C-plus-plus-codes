class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) 
    {
        int maxLen=0;
        //test case
        if(s.length()==0)
        {
            return maxLen;
        }
        int start=0,end=0;
        unordered_map<char,int> dict;
        
        while(end<s.length())
        {
            char c=s[end];
            //if the char is in dict, increase the frequency
            dict[c]++;
            
            //if the dict size is>2, balance it
            while(dict.size()>2)
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
