class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int row=grid.size();
        int col=grid[0].size();
        if((row+col)==0)
            return 0;
        
        queue<vector<int>>  q;
        
        vector<int> xdr = {0,0,1,-1};
        vector<int> ydr = {1,-1,0,0};
        int result=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==2)// && visited[i][j]==false)
                {
                    q.push({i,j});
                }
            }
        }
           
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;++i)
            {
                auto front=q.front();
                q.pop();
                int currX=front[0];
                int currY=front[1];
                cout<<"currX: "<<currX<<"\t"<<"currY: "<<currY<<endl;

                for(int k=0;k<4;k++)
                {
                    int nextX=currX+xdr[k];
                    int nextY=currY+ydr[k];

                    if(nextX>=0 && nextX<grid.size() && nextY>=0 &&nextY<grid[0].size()
                       && grid[nextX][nextY]==1)
                    {
                        grid[nextX][nextY]=2;
                        q.push({nextX,nextY});
                    }

                }
            }
            result++;

        }
        
        for(size_t i=0;i<grid.size();++i)
        {
            for(size_t j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        
        //we need to retun result-1 because the question starts at min 0, see the pic
        if((result-1)>=0)
            return (result-1);
        
        return 0;
    }
};
