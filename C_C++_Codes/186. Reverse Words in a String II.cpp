// Firstly reverse every word in the string and than reverse the
// whole string. Finally, remove the extra spaces
/*
Example:

Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]*/
class Solution {
public:
    void reverseWords(vector<char>& s) 
    {
        //test case
        if(s.size()==0)
        {
            return;
        }
        
        //reverse the string
        reverse(s.begin(),s.end());
        int i=0; 
        
        //reverse individual words
        for(int  j=0; j <= s.size();j++)
        {
            if( j==s.size() || s[j]==' ')
            {
                helper(s,i,j-1);
                i = j+1;
            }
        } 
    }
    
     void helper(vector<char>& s, int i, int j)
     {
         while(i <j)
         {
             char temp = s[i]; 
             s[i]=s[j];
             s[j]=temp; 
             i++; 
             j--;
         }
     }        
};
