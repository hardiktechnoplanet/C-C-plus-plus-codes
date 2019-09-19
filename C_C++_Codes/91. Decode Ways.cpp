//Solution1: Dynamic Programming (bottom-up)
class Solution {
public:
    int numDecodings(string s) 
    {
        //Corner case - 
        if(s[0]=='0')
            return 0;
        
        //General case - 
        vector<int>mem(s.length()+1);
        //dp[i] = number of ways to decode the string till length i
        
        //base case
        mem[0] = 1; //one way to decode an empty string
        mem[1] = 1;
        
        for(int i=2;i<=s.length();i++){
            int oneDigit = stoi(s.substr(i-1,1));
            int twoDigits = stoi(s.substr(i-2,2));
            
            //check if there is any mapping
            if(oneDigit>=1)
                mem[i]=mem[i]+mem[i-1];
            
            if(twoDigits>=10 && twoDigits<=26)
                mem[i]=mem[i]+mem[i-2];
        }
        
        return mem[s.length()];
    }
};

//Solution2: Dynamic programming with recursion
/*
class Solution {
public:
    int numDecodings(string s) 
    {
        vector<int> mem(s.length(),-1);
        return numDecodingsHelper(s,0,mem);
    }
    int numDecodingsHelper(string& s, int pointer, vector<int>& mem)
    {
        //base case
        if(pointer>=s.length())
        {
            return 1;
        }
        
        //if we already know the ans
        if(mem[pointer]>-1)
        {
            return mem[pointer];
        }
        
        //We don't already know the answer to this subproblem, calculate it
        //by taking the sum of the total ways for a single character decoring
        //or 2 character decoding
        
        int totalWaysFromHere = 0;
        //taking single char
        if(pointer+1<=s.length())
        {
            string subStr=s.substr(pointer,pointer+1);
            //check if this subStr is valid
            if(isValid(subStr))
            {
                totalWaysFromHere +=numDecodingsHelper(s,pointer+1,mem);
            }
        }
        
        //taking two char's
        if(pointer+2<=s.length())
        {
            string subStr=s.substr(pointer,pointer+2);
            //check if this subStr is valid
            if(isValid(subStr))
            {
                totalWaysFromHere +=numDecodingsHelper(s,pointer+2,mem);
            }
        }
        
        mem[pointer]=totalWaysFromHere;
        
        return mem[pointer];
    }
    
    bool isValid(string s)
    {
        

          if (s.length() == 0) 
          {
              return false;
          }

          if (s[0] == '0') 
          {
              return false;
          }

          int value =stoi(s);

          return value >= 1 && value <= 26;
    }
};
*/
