//Least number of moves =shortest distance =BFS
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        //Convert board in 1D vector
        int row = board.size();
        int col = board[0].size();
        int n = row*col;
        vector<int> move(n);
        
        int index=0,inc=1;
        int i=row-1,j=0;
        while(index<n)
        {
            cout<<index<<"  "<<i<<"  "<<j<<endl;
            move[index++]=board[i][j];
            if(j==col-1&&inc==1)
            {
                i--;
                inc=-1;
                continue;
            }
            if(j==0&&inc==-1){
                i--;
                inc=1;
                continue;
            }
            j+=inc;
        }
        
        //make a visited vector
        vector<bool> visited (n,false); 
        
        // Create a queue for BFS 
        queue<int> q; 

        // Mark the node 0 as visited and enqueue it. 
        visited[0] = true; 
         
        //first index of the board is 0, push it in the queue
        q.push(0);
        int steps=0;
        
        // Do a BFS starting from vertex at index 0  
        while (!q.empty()) 
        { 
            int qSize=q.size();
            while(qSize>0)
            {
                int index = q.front();  

                // If front index is the destination vertex, 
                // we are done 
                if (index == n-1) 
                    return steps; 

                // Otherwise dequeue the front vertex and enqueue 
                // its adjacent vertices (or cell numbers reachable 
                // through a dice throw) 
                q.pop(); 
                qSize--;
                //there are 6 possible index's the player can go from one index
                for (int j=index+1; j<=(index+6) && j<n; ++j) 
                { 
                    int next;
                    //if there is no snake or ladder, the next index will
                    //be j itself
                    if(move[j]==-1)
                        next=j;
                    //otherwise go to the tip of the snake or whereever ladder takes us
                    else
                        next=move[j]-1; //-1 because board is zero indexed
                    
                    // If this cell is already visited, then ignore 
                    if (!visited[next]) 
                    { 
                        // Otherwise mark it as visited 
                        visited[next] = true; 
                        
                        //push it to the queue
                        q.push(next);
                    } 
                } 
            }
            steps++;
        } 

        // We reach here when 'index' has last vertex 
        // return -1 
        return -1; 

        
    }
};
