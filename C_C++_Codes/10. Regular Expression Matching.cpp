//Time Comlexity and space complexity O(nxm) where n is length of s and m is 
//length of p
class Solution {
public:
    bool isMatch(string s, string p) 
    {
        vector<vector<bool>> T (s.length()+1,vector<bool>(p.length()+1,false));
        
        //empty s and empty p will always match
        T[0][0]=true;
        
        //0th column will be all false (except T[0][0]) because it represents that
        //p is empty and s is not
        
        //0th row will not contains all values as false for some cases
        //a* or a*b*
        for(size_t i=1;i<T[0].size();++i)
        {
            if(p[i-1]=='*')
            {
                T[0][i]=T[0][i-2];
            }
        }
        
        for(size_t i=1;i<T.size();++i)
        {
            for(size_t j=1;j<T[0].size();++j)
            {
                //case I: if there is '.' or chars are same
                if(p[j-1]=='.' || p[j-1]==s[i-1])
                {
                    //we can remove this char and check if the leftover string matches
                    //it means that we need to check the diagonally left value
                    T[i][j]=T[i-1][j-1];
                }
                
                //case II
                else if(p[j-1]=='*')
                {
                    //case I: zero occurence of this char
                    T[i][j]=T[i][j-2];
                    //case II: one or more occurence 
                    if(p[j-2]=='.' || p[j-2]==s[i-1])
                    {
                        T[i][j]=T[i][j] | T[i-1][j];
                    }
                }
                else
                {
                    T[i][j]=false;
                }
            }
        }
        return T[s.length()][p.length()];
        
    }
};
