/*Check leet code solution and https://leetcode.com/problems/fraction-to-recurring-decimal/discuss/51160/C%2B%2B-unordered_map*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) 
    {
        //test case
        if(numerator==0)
            return "0";
        string result;
        
        //if either of num or den is -ve (not both)
        if(numerator<0 ^ denominator<0)
            result+="-";
        
        //convert to long to handle overflow
        long n=labs(numerator);
        long d=labs(denominator);
        result+=to_string(n/d);
        long remainder=n%d;
        
        //if the remainded is 0, return the result
        if(remainder==0)
            return result;
        
        //check for recurring remainder
        result+=".";
        unordered_map<long,int> hashMap;
        
        while(remainder!=0)
        {
            //if the remainder is in hashMap=>it is recurring
            if(hashMap.find(remainder)!=hashMap.end())
            {
                result.insert(hashMap[remainder],"(");
                result+=")";
                break;
            }
            hashMap[remainder]=result.length();
            remainder*=10;
            result+=to_string(remainder/d);
            remainder%=d;
        }
        return result;  
    }
};
