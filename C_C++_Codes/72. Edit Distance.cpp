class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int len1=word1.length(),len2=word2.length();
        
        //test case
        //if one of the strings is empty
        if(len1*len2==0)
        {
            return len1+len2;
        }
        vector<vector<int>> T (len1+1, vector<int>(len2+1,0));
        //fill th first col
        for(size_t i=0;i<=len1;++i)
        {
            T[i][0]=i;
        }
        
        //fill th first row
        for(size_t i=0;i<=len2;++i)
        {
            T[0][i]=i;
        }
        
        for(size_t i=1;i<=len1;++i)
        {
            for(size_t j=1;j<=len2;++j)
            {
                //if current char are same
                if(word1[i-1]==word2[j-1])
                {
                    //take the diagonal value as we dont have to use
                    //any operation for the same chars
                    T[i][j]=T[i-1][j-1];
                }
                else
                {
                    //find min of top, left, and diagonal element +!
                    int minVal=min(T[i-1][j-1], T[i-1][j]);
                    T[i][j]=1 + min(minVal, T[i][j-1]);
                }
            }
        }
        return T[len1][len2];
    }
};
