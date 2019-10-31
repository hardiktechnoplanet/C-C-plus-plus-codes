//First, find out the trees lenght and x,y corrdinates in a vector of vector. Sort this vector because
//we need to cut the trees in increasing order. Traverse through this vector and find the distance to the next
//tree in vector using bfs.

class Solution {
public:
    vector<int> xdir = {0,0,1,-1};
    vector<int> ydir = {1,-1,0,0};
    
    bool isvalid(int& x,int& y,vector<vector<int>>& forest){
        if(x<0||y<0||x==forest.size()||y==forest[0].size()){
            return 0;
        }
        return 1;
    }
    
    //bfs
    int distance(vector<int>& start,vector<int>& end,vector<vector<int>>& forest)
    {
        //if start and end position are same
        if(start[0]==end[0]&&start[1]==end[1])
        {
            return 0;
        }
        queue<vector<int>> x;
        x.push(start);
        int steps=0;
        vector<vector<int>> visited(forest.size(),vector<int>(forest[0].size(),0));
        visited[start[0]][start[1]]=1;
        while(!x.empty())
        {
            int n = x.size();
            while(n>0)
            {
                auto curr = x.front();
                x.pop();
                n--;
                int currx = curr[0];
                int curry = curr[1];
                
                //there are 4 places we can go
                for(int i=0;i<4;i++)
                {
                    int nextx = currx + xdir[i];
                    int nexty = curry + ydir[i];
                    if(isvalid(nextx,nexty,forest)&&visited[nextx][nexty]==0&&forest[nextx][nexty]!=0){
                        if(nextx==end[0]&&nexty==end[1]){
                            return steps+1;
                        }
                        x.push({nextx,nexty});
                        visited[nextx][nexty]=1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
            
    
    int cutOffTree(vector<vector<int>>& forest) 
    {
        //save the tree length and coordinates of that tree in
        //trees vector
        vector<vector<int>> trees;
        
        for(int i=0;i<forest.size();i++)
        {
            for(int j=0;j<forest[0].size();j++)
            {
                if(forest[i][j]>1)
                {
                    trees.push_back({forest[i][j],i,j});
                }
            }
        }
        
        sort(trees.begin(),trees.end());
        int ans=0;
        vector<int> start = {0,0};
        
        for(int i=0;i<trees.size();i++)
        {
            //next vector contains the coordinates of the next tree in line
            vector<int> next = {trees[i][1],trees[i][2]};
            //find the distance to reach the next tree
            int dis = distance(start,next,forest);
            if(dis==-1){
                return -1;
            }
            start = next;
            ans+=dis;
        }
        return ans;
        
    }
};
                    
                
