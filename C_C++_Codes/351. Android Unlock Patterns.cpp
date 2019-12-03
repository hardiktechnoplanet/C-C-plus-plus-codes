//https://medium.com/@rebeccahezhang/leetcode-351-android-unlock-patterns-d9bae4a8a958
//https://www.geeksforgeeks.org/number-of-ways-to-make-mobile-lock-pattern/
class Solution {
public:
    int result=0;
    #define DOTS 10 
    int numberOfPatterns(int m, int n) 
    {
        vector<vector<int>> skip (10,vector<int>(10,0));
        //  2 lies between 1 and 3 
        skip[1][3] = skip[3][1] = 2; 

        //  8 lies between 7 and 9 
        skip[7][9] = skip[9][7] = 8; 

        //  4 lies between 1 and 7 
        skip[1][7] = skip[7][1] = 4; 

        //  6 lies between 3 and 9 
        skip[3][9] = skip[9][3] = 6; 

        //  5 lies between 1, 9  2, 8  3, 7 and 4, 6 
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] 
         = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5; 

        //visited vector
        vector<bool> visited(10,false);
        int result=0;
        
        for(int i=m;i<=n;i++)
        {
            //  1, 3, 7, 9 are symmetric so multiplying by 4 
            result+=dfsHelper(skip,visited,1,i-1)*4;
            
            //  2, 4, 6, 8 are symmetric so multiplying by 4 
            result += dfsHelper(skip, visited, 2, i - 1) * 4;
            
            result += dfsHelper(skip, visited, 5, i - 1);
        }
        
        return result;
    }
    
    int dfsHelper(vector<vector<int>> skip, vector<bool>& visited, int cur, int remain)
    {
        //base case: out of bound
        if(remain<0)
            return 0;
        //base case: no remaining numbers
        if(remain==0)
            return 1;
        
        //mark number as visited
        visited[cur]=true;
        int res=0;
        
        for(int i=1;i<=9;i++)
        {
            // Next key must be not visited
            // Current key and next key are adjacent or skip number is already visited
            if(visited[i]==false && (skip[cur][i]==0 || visited[skip[cur][i]]==true))
                res+=dfsHelper(skip,visited,i,remain-1); 
        }
        // Mark as unvisited for the rest of recursion calls after return from the first one  
        visited[cur] = false;
        return res;
    }
};
