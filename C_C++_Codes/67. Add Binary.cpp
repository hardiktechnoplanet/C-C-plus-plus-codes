//https://www.youtube.com/watch?v=tRpusgdZxrE
class Solution {
public:
    string addBinary(string a, string b) 
    {
        string result="";
 
        int i=a.length()-1, j=b.length()-1;
        int carry=0;
        while(i>=0 || j>=0)
        {
            int sum=carry;
            if(i>=0)
            {
                //offset the char and convert it to a number
                sum+=a[i]-'0';
                i--;
            }
            if(j>=0)
            {
                sum+=b[j]-'0';
                j--;
            }
            //add the result to the string and recalculate the carry
            //for next iteration.
            
            //sum can be 0,1 or 2. sum=0=>sum%2=0, sum=1=>sum%2=1
            //and sum=2=>sum%2=0
            result.insert(0,1,sum%2+'0');
            carry=sum/2; //if sum=2, carry=1, if sum<2, carry=0;
        }
        if(carry>0)
            result.insert(0,1,1+'0');
        
        return result;

    }
};
