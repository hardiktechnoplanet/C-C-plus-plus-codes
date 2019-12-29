class Solution {
public:
    int romanToInt(string s) 
    {
        if(s.length()==0)
            return 0;
        
        unordered_map<char,int> T={{'I',1}, {'V',5}, {'X',10}, {'L',50},
                                   {'C',100}, {'D',500}, {'M',1000}};
        
        //sum contains the int value of last element in string
        int sum=T[s.back()];
        
        //start from the second last element in the string
        for(int i=s.length()-2;i>=0;--i)
        {
            //if the symbol after the curr is >, subtract the curr symbol
            if(T[s[i]]<T[s[i+1]])
                sum-=T[s[i]];
            else
                sum+=T[s[i]];
        }
        return sum;
        
    }
};
