class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> result;
        
        for(int i=1;i<=n;++i)
        {
            bool divisibleBy3=false, divisibleBy5=false;
            if(i%3==0)
            {
                divisibleBy3=true;
            }
            if(i%5==0)
            {
                divisibleBy5=true;
            }
            
            string ans="";
            
            if(divisibleBy3)
            {
                ans+="Fizz";
            }
            if(divisibleBy5)
            {
                ans+="Buzz";
            }
            if(ans=="")
            {
                ans+=to_string(i);
            }
            result.push_back(ans);
            
        }
        return result;
        
    }
};
