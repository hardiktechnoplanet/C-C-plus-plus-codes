class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if(matrix.size()==0)
        {
            return 0;
        }
        int maxSquare=0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> T(m+1,vector<int>(n+1,0));
        
        for(size_t i=1;i<=m;++i)
        {
            for(size_t j=1;j<=n;++j)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    //find min of top,left,top left diagonal element and add
                    //1 to it
                    int minEle=min(T[i][j-1],T[i-1][j]);
                    T[i][j]=min(minEle,T[i-1][j-1])+1;
                    maxSquare=max(maxSquare,T[i][j]);
                }
            }
        }
        return maxSquare*maxSquare;
        
    }
};
