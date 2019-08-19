//We need to check if there is a circle in the graph. We will put the prerequisites relation
//in the vector of vector, visiting nodes in visiting set, visited nodes in visited vector.
//We will visit a node and put that node and its childrens (childrens of childrens till the visiting child
//is already in visited vector) in the visiting set. Once visited, we will put them in visited vector. 
//If the current visiting node is already in the visiting set, there is a cycle and the hepler function will
//return true

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        //to store the prerequisites relation
		vector<vector<int>> graph(numCourses);
        //fill the dependency graph
        for(int i=0;i<prerequisites.size();++i)
        {
            //to take the course at [i][0], we have to take [i][1]
			graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        //for visiting nodes
        unordered_set<int> visiting;
        //for visited nodes
        vector<bool> visited(numCourses,false);
        
        //if helper function founds a cycle, it will return true and we will
        //return false
        for(int node=0;node<numCourses;++node)
        {
            if (dfsHelper(node,graph,visiting,visited))
            {
                return false;
            }
        }
        return true;
    }
    
    bool dfsHelper(int node,const vector<vector<int>>& graph,unordered_set<int>& visiting,vector<bool>& visited)
    {
        //base case
        //if visiting node is already in visiting set,
        //return false (it implies a circle)
        if(visiting.find(node)!=visiting.end())
        {
            return true;
        }
        
        //if the current node is already visited, no need to
        //visit it again
        if(visited[node])
        {
            return false;
        }
        
        //if the node is not already visited, put it in visiting set
        visiting.insert(node);
        //for all the neighbors of this node, call the helper function
        for(const int neigh:graph[node])
        {
            if(dfsHelper(neigh,graph,visiting,visited))
            {
                //if there is circle, return true to all the way up
                return true;
            }
        }
        
        //the node is visited now, remove it from visiting set
        visiting.erase(node);
        //mark the node in visited vector
        visited[node]=true;
        
        //no circle, so return false
        return false;
    }
};
