//Two pointer solution
class Solution {
public:
    string reverseVowels(string s) 
    {
        int left=0,right=s.length()-1;
        char ls,rs;
        
        while(left<right)
        {
            ls=s[left];
            rs=s[right];
        
            if(isVowel(s[left]) && isVowel(s[right]))
            {
                s[left]=rs;
                s[right]=ls;
                left++;
                right--;
            }
            else if (isVowel(s[left])) 
            { 
                right--; 
            }
            else
            {
                left++;
            }
 
        }
        return s;
        
    }
    bool isVowel(char c)
    {
        return (c=='a' || c=='A' || c=='e' || 
            c=='E' || c=='i' || c=='I' || 
            c=='o' || c=='O' || c=='u' || 
            c=='U'); 
    }
};
