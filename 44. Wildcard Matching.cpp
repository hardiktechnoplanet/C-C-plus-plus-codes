/*O(n*m) (size of s * size of p)
Solution1: DP
https://www.youtube.com/watch?v=3ZDZ-N0EPV0*/
class Solution {
public:
    bool isMatch(string str, string ptr) 
    {
        //convert the strings in char array
        char s[str.length()+1];
        char p[ptr.length()+1];
        for(size_t i=0;i<str.length();++i)
        {
            s[i]=str[i];
        }
        for(size_t i=0;i<ptr.length();++i)
        {
            p[i]=ptr[i];
        }
        //replace multiple consecutive * with a single *
        //ex: a**b***c = a*b*b
        int temp=0;
        bool firstTime=true;
        for(size_t i=0;i<p.size();++i)
        {
            if(p[i]=='*')
            {
                if(firstTime)
                {
                    p[temp++]=p[i];
                    firstTime=false;
                }
            }
            else
            {
                p[temp++]=p[i];
                firstTime=true;
            }
            
        }
        
        //initialize a 2d vector to store the result
        vector<vector<int>> memo(s.size() + 1, vector<int>(p.size() + 1));
        
        //an empty string and empty pattern will match
        memo[0][0]=1;
        
        //only a * can match the empty string
        if (temp > 0 && p[0] == '*') 
        {
            memo[0][1] = 1;
        }
        
        for(size_t i=1;i<memo.size();++i)
        {
            for(size_t j=1;j<memo[0].size();++i)
            {
                //if the current char matches or if there is "?" in the pattern
                if(p[j-1]=='?' || p[j-1]==s[i-1])
                {
                    //check the diagonal element
                    memo[i][j]=memo[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    //take the value from left or top
                    //remove the current char in s and match or remove the *
                    //from p and match (* represents null char here)
                    memo[i][j]=memo[i-1][j] || memo[i][j-1];
                }
            }
        }
        return memo.back().back();
    }
};


/*Recursive solution*/
/*
bool isMatch(string s,string p)
{
    return helper(s,p,0,0);
}
bool helper(string& s, string& p, int pos1,int pos2)
{
    //base case
    if(pos2==p.length())
    {
        return pos1==s.length();
    }
    
    //case if the current char is not '*'
    if(p[pos2]!='*')
    {
        if(pos1<s.length() && (s[pos1]==p[pos2]) || p[pos2]=='?')
        {
            return helper(s,p,pos+1,pos2+1);
        }
        else
        {
            return false;
        }
    }
    else
    {
        
        //if we have a***b then skip to the last *
        while (pos2 < p.length() - 1 && p[pos2 + 1] == '*') 
        {
            pos2++;
        }
        pos1--;
            while (pos1 < s.length()) {
                if (helper(s, p, pos1 + 1, pos2 + 1)) {
                    return true;
                }
                pos1++;
            }
            return false;
        
    }
    
}*/
