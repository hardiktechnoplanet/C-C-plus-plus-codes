//https://www.youtube.com/watch?v=_nCsPn7_OgI&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=9

class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        //test case
        if(s.length()==0)
            return 0;
        
        vector<vector<int>>T (s.length(),vector<int>(s.length(),0));
        
        for(size_t i=0;i<s.length();++i)
        {
            T[i][i]=1;
        }
        
        for(int l = 2; l <= s.length(); l++)
        {
            for(int i = 0; i < s.length()-l + 1; i++)
            {
                int j = i + l - 1;
                if(l == 2 && s[i] == s[j])
                {
                    T[i][j] = 2;
                }
                else if(s[i] == s[j])
                {
                    T[i][j] = T[i + 1][j-1] + 2;
                }
                else
                {
                    T[i][j] = max(T[i + 1][j], T[i][j - 1]);
                }
            }
        }
        return T[0][s.length()-1];
    }
};


/*Recursive Solution:https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
// Every single character is a palindrome of length 1
L(i, i) = 1 for all indexes i in given sequence

// IF first and last characters are not same
If (X[i] != X[j])  L(i, j) =  max{L(i + 1, j),L(i, j - 1)} 

// If there are only 2 characters and both are same
Else if (j == i + 1) L(i, j) = 2  

// If there are more than two characters, and first and last 
// characters are same
Else L(i, j) =  L(i + 1, j - 1) + 2 
*/

/*
class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        return helper(s,0,s.length()-1);
    }
    
    int helper(string& s,int i, int j)
    {
        //base case
        //if there is only one char
        if(i==j)
            return 1;
        
        //if 2 chars left and both are same
        if(s[i]==s[j] && (i+1==j))
        {
            return 2;
        }
        
        //if first and last char matches
        if(s[i]==s[j])
        {
            return helper(s,i+1,j-1)+2;
        }
        
        //if first and last char are not same
        return (max(helper(s,i+1,j), helper(s,i,j-1)));  
    }
};*/
