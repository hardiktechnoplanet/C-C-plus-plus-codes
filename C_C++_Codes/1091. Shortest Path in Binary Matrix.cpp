/*Shortest path means BFS. We have to traverse from first index to the last index and
we can only go to the node having value 0. From a node, we can go in 8 directions.

Start from first index, run BFS. From every node, go in 8 directions and check which of the index
is valid. Repeat this process for every level*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        //test cases
        int row = grid.size();
        if (row == 0) 
            return -1;
        int col = grid[0].size();
        if (col == 0 ) 
            return -1;
        if (grid[0][0] != 0 | grid[row-1][col-1] != 0) 
            return -1;

        //BFS
        queue<vector<int>> q;
        //push the starting index in the queue
        q.push({0,0});
        
        //make a direction array, we can go in 8 directions from the current node
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        
        //vector to keep all the visited nodes
        vector<vector<bool>> visited (row,vector<bool>(col,false));
        visited[0][0]=true;
        
        int level=0;
        
        while(!q.empty())
        {
            int size=q.size();
            while(size>0)
            {
                auto curr = q.front();
                int currX = curr[0];
                int currY = curr[1];
                
                //check if we have reached to the end of the grid
                if( currX == row -1 && currY == col -1) 
                    return level+1;
                
                q.pop();
                size--;

                for(auto direction : directions)
                {
                    int nextX = currX + direction[0];
                    int nextY = currY + direction[1];
                    
                    //check if this index is valid
                    if(nextX >= 0 && nextX < row && nextY >= 0 && nextY < col 
                       && visited[nextX][nextY] == false && grid[nextX][nextY]==0)
                    {
                        q.push({nextX,nextY});
                        visited[nextX][nextY] = true;
                    }
                }  
            }
            level++;
            
        }
        return -1;
        }

};
