//We will use 2 pointers starting from index 0. We will increment the right
//pointer till we find all the required characters. We will store this window
//and its length. Now, we will increment the left pointer and check if all the
//required chars are still there. Accordingly, we will updated the window and the
//length to find the shortest one.
class Solution {
public:
    string minWindow(string s, string t) {
        
        //test case
        if(s.length()==0 || t.length()==0 || s.length()<t.length())
        {
            return "";
        }
        string minString="";
        int min=INT_MAX;
        //map will store the number of occurence of chars in string t
        unordered_map<int,int> bank;
        int left=0,right=0,count=0;
        
        for(int i=0;i<t.length();++i)
        {
            bank[t[i]]++;
        }
        
        while(right<s.length())
        {
            //if the current element in s is also in t
            //increment the right pointer and count
            if(bank[s[right++]]-- >0)
            {
                count++;
            }
            //if all the chars are found, update the minLen and substring.
            //Slide the left pointer to decrease the window size
            while(count==t.length())
            {
                if(min>right-left)
                {
                    min=right-left;
                    minString=s.substr(left,right-left);
                }
                //shift the window
                if(++bank[s[left++]]>0)
                {
                    count--;
                }
            }
        }
        return minString;
    }
};
