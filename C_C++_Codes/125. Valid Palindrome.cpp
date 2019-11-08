//two pointers approach

class Solution {
public:
    bool isPalindrome(string s) 
    {
        if(s.length()==0)
            return true;
        
        int left=0,right=s.length()-1;
        while(left<right)
        {
            //if both are number or chars, compare them, if same => increment
            //left and decrement right otherwise return false
            if(isalnum(s[left]) && isalnum(s[right]))
            {
                if(tolower(s[left])==tolower(s[right]))
                {
                    left++;
                    right--;
                }
                else
                {
                    return false;
                }
            }
            //if left is neither num nor char, increment the left
            else if(!isalnum(s[left]))
                left++;
            
            //if right is neither num nor char, decrement the right
            else
                right--;
        }
        return true;
        
    }
};
