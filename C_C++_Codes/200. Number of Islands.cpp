//traverse the grid, we are only concerned with '1's'. Where ever there is a 1,
//call the helper funtion to check its neighbours. Make all the visited 1 as 0
//so that we dont traverse it again

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int numIsland=0;
        
        for(size_t i=0;i<grid.size();++i)
        {
            for(size_t j=0;j<grid[i].size();++j)
            {
                //we only need to take care of 1's
                if(grid[i][j]=='1')
                {
                    //make a dfs call to check if its neighbours are 1 or 0
                    //if they are 1, make them 0 so that we dont visit them again
                    numIsland +=dfsHelper(grid,i,j);
                }
            }
        }
        return numIsland;
        
    }
    int dfsHelper(vector<vector<char>>& grid, int i,int j)
    {
        //base case
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || grid[i][j]=='0' )
        {
            return 0;
        }
        //make that node as 0 (visited), so that we dont visit that again
        grid[i][j]='0';
        
        //recursion
        //check the neighbors of 1 to find other 1's to form an island
        dfsHelper(grid,i+1,j); //top
        dfsHelper(grid,i-1,j); //bottom
        dfsHelper(grid,i,j+1); //right
        dfsHelper(grid,i,j-1); //left
        return 1;
        
    }
};
