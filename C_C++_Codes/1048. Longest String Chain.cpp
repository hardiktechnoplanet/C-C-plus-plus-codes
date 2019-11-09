class Solution {
public:
    int longestStrChain(vector<string>& words) {
        if(words.size() == 1) return 1;
        
        // Sort words in assending order of size
        sort(words.begin(),words.end(),[](string &a,string &b){return a.size() < b.size();});
        
        int n = words.size();
        
        // dp[i] represents longest chain from index i till n-1 index
        vector<int> dp(n,1);
        int maxChain = 1;
        
        // for n-1 index longest chain contains only words[n-1]
        // for every index from n-2 to 0, retrive the longest chain after it.
        for(int i=n-2; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
            {
                if(words[j].size() == words[i].size()+1){
                    
                    // If words[i] is predecessor of words[j] than chain will be incremented by 1
                    // Store max of all chains possible from words[i]
                    if(isPred(words[i],words[j]))
                    {
                        dp[i] = max(dp[i],dp[j]+1);
                    } 
                }
                
                // Difference of exactly one letter
                else if(words[j].size() > words[i].size()+1)
                    break;
            }
            
            // If chain from words[i] is longest than store it in maxChain
            maxChain = max(maxChain,dp[i]);
        }       
        return maxChain;
    }
    
   
    
    
    //To Check if string sa is predicessor of sb
    bool isPred(string sa,string sb){
        
        // Store frequency of letters from 'a'->'z' of both string        
        vector<int> fa(26,0);
        vector<int> fb(26,0);
        
        for(char ch: sa){
            fa[ch-'a']++;
        }
        for(char ch: sb){
            fb[ch-'a']++;
        }
        
        // If a character is in sa string then it must be sb string with same or more frequency
        int changes=0;
        for(int i=0;i<26;i++){
            if(fb[i] < fa[i]) return false;
            if(fb[i] > fa[i]){
                changes++;
                if(changes > 1) return false;
            }
        }
        
        // Changes should be of exactly one letter
        if(changes != 1) return false;
        return true;
    }
};
