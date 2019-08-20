//Recursive solution
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        //unordered_map<string,bool> memory;
        vector<int> memory(s.length(),-1);
        
        for(size_t i=0;i<wordDict.size();++i)
        {
            dict.insert(wordDict[i]);
        }
        //call the helper function
        return wordBreakHelper(s,dict,0,memory);
    }
    
    bool wordBreakHelper(string s, unordered_set<string> dict, int start,vector<int>& memory)
    {
        
        if(start==s.length())
        {
            return true;
        }
        
        //here the memory[i]=1 means that the string from index i to end of string
        //is already present.
        if(memory[start]!=-1)
        {
            return memory[start];
        }

        for(int len=1;len<=s.length()-start;++len)
        {
            string prefix=s.substr(start,len);
            //cout << "value:" << prefix << endl;
            if(dict.find(prefix)!=dict.end() &&(wordBreakHelper(s,dict,start+len,memory)))
            {
                memory[start]=1;
                return true;
            }          
        }
        memory[start]=false;
        return false;
    }
};


//Iterative solution
class Solution {
public:
   
    
    unordered_set<string> hash;
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(int i=0;i<wordDict.size();i++){
            hash.insert(wordDict[i]);
        }
        vector<int> dp(s.length(),0);
        string temp="";
        temp+=s[0];
        if(hash.find(temp)!=hash.end()){
            dp[0]=1;
        }
        
        //memory[i] represents the string from index 0 to i.
        //suppose i=3, the if loop will first check if the string from
        //index 0 to 2 is there or not. If it is there, it will check if string[3]
        //is present or not. 
        //When j=0, the lower if loop will check if the string from index 0 to i+1 is 
        //there or not.
        //Example, i=2, string is "lee", the "if" loop will check if "le" is present. If
        //it is present, it will check if "e" is present. If not, the lower "if" will check
        //if the "lee" is present.
        for(int i=1;i<s.length();i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    //if j tak h toh j to i check kro
                    if(hash.find(s.substr(j+1,i-j))!=hash.end()){
                        dp[i]=1;
                        break;
                    }
                }
                //check if the string of length i (starting from index 0) is present or not
                if(j==0){
                    if(hash.find(s.substr(0,i-j+1))!=hash.end()){
                        dp[i]=1;
                        break;
                    }
                }
            }
        }
        return dp[s.length()-1];      
    }
};
