/*"All possible => backtracking"
https://www.youtube.com/watch?v=4ykBXGbonlA
Time Complexity: O(n * 2^n), Space Complexity: O(n)
*/
class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> result;
        if(s.length()==0)
            return result;
        
        vector<string> chosen;
        helper(s,0,chosen,result);
        return result;
    }
    
    void helper(string s, int index, vector<string>& chosen, vector<vector<string>>& result)
    {
        //base case
        if(index==s.length())
        {
            result.push_back(chosen);
            return;
        }
        
        //Take every snippet take from the 'index' to the end of the
        //string. This is out 'possibility space' that we can recurse into.
        for(size_t i=index; i<s.length();++i)
        {
            cout<<s.substr(index,i-index+1)<<"\t"<<i<<"\t"<<index<<endl;
            
            //Only recurse if the snippet from 'index' (inclusive) to
            //s.length() (inclusive) is a palindrome
            if(isPalindrome(s,index,i))
            {
                //Choose
                chosen.push_back(s.substr(index,i-index+1));
                //Explore
                helper(s,i+1,chosen,result);
                //Unchoose
                chosen.pop_back();
            }
                
        }
    }
    
    bool isPalindrome(string s,int start, int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
};
