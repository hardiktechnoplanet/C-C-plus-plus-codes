//Make a priority queue, traverse through the vector and insert eucd dist and vector index
//in the priority queue. Now, pq will have eucd distance arranged in increasing order along
//with the vector index. Now, traversed for K times and put the index stored in minHeap to 
//the result vector
class Solution {
public:
    typedef pair<float, int> pi;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
        vector<vector<int>> result;
        //test case
        if(points.size()==0)
        {
            return result;
        }
        
        //minHeap to store the distance and index (increading order) 
        //of the corresponding point
        priority_queue<pi,vector<pi>,greater<pi>> minHeap;
        int size=points.size();
        for(int i=0;i<size;i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            float dist=sqrt(x*x + y*y);
            cout<<dist<<endl;
            minHeap.push(make_pair(dist,i));
        }
        
        //Traverse for K times and push the index stored in minHeap to the vector
        while(K--)
        {
            int index=minHeap.top().second;
            result.push_back(points[index]);
            minHeap.pop();
        }
        return result;
    }
    
};
