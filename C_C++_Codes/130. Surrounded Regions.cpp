/* Step 1: Find the 'O' on the border (first and last row and col). If there is
any 'O' on the border, run the dfs to find its connected components. Replace
these connected components with some random value say '*'. 

Step 2: Now, loop through the board, replace 'O' with 'X' and '*' with 'O'.

Time and Space complexity :O(mn)*/
class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        //test cases
        if(board.size()<2 || board[0].size()<2)
            return;
        
        //check the border elements, if 'O' is found, run the DFS
        //and turn all the connected elements to some random char say '*'
        
        int rows=board.size();
        int cols=board[0].size();
        
        //check in the first and last rows
        for(size_t i=0;i<cols;++i)
        {
            //first row
            if(board[0][i]=='O')
            {
                dfsHelper(board,0,i);
            }
            //last row
            if(board[rows-1][i]=='O')
            {
                dfsHelper(board,rows-1,i);
            }
        }
        
        //check in the first and last columns
        for(size_t i=0;i<rows;++i)
        {
            //first col
            if(board[i][0]=='O')
            {
                dfsHelper(board,i,0);
            }
            //last col
            if(board[i][cols-1]=='O')
            {
                dfsHelper(board,i,cols-1);
            }
        }
        
        //post-prcessing, turn 'O' to 'X', '*' back to 'O', and keep 'X' as it is.
        for(size_t i=0;i<rows;++i)
        {
            for(size_t j=0;j<cols;++j)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='*')
                    board[i][j]='O';
            }
        }
    }
    
    void dfsHelper(vector<vector<char>>& board, int i, int j)
    {
        //base case
        if(i<0 || i>=board.size()||j<0 || j>=board[1].size() || board[i][j]=='X' || board[i][j]=='*')
        {
            return;
        }
        
        //mark the node as visited
        board[i][j]='*';
        
        //we can go to 4 different locations from here
        dfsHelper(board,i-1,j);
        dfsHelper(board,i+1,j);
        dfsHelper(board,i,j-1);
        dfsHelper(board,i,j+1);
    }
};
