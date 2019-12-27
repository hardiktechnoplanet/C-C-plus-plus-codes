//Same as next permutation 31 leetcode
class Solution {
public:
    int nextGreaterElement(int n) 
    {
        string s = to_string(n);
        cout<<s<<endl;
        //test case
        if (s.length() == 1) {
            return -1;
        }
        
        int i=s.length()-2;
        while(i>=0 && s[i]>=s[i+1])
            i--;
        
        if(i<0)
            return -1;
        
        else if(i>=0)
        {
            int j=s.length()-1;
            while(j>=0 && s[j]<=s[i])
            {
                j--;
            }
            swap(s,i,j);
        }
        reverse(s,i+1,s.length());
        auto res = stoll(s);
        return (res > INT_MAX || res <= n) ? -1 : res;
        
    }
   void reverse(string& s, int start,int len)
   {
        int i = start, j = len - 1;
        while (i < j) 
        {
            swap(s, i, j);
            i++;
            j--;
        }
    }

    void swap(string& s, int i, int j) 
    {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

};
