class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) 
    {   
        int i=0, j=0;
        vector<vector<int>> result;
          
        while(i<A.size() && j<B.size())
        {
            // Let's check if A[i] intersects B[j].
            // start - the startpoint of the intersection
            // end - the endpoint of the intersection
            int start = max(A[i][0], B[j][0]);
            int end = min(A[i][1], B[j][1]);
            
            if(start <= end) 
                result.push_back(vector<int>{start, end});
            
            // Remove the interval with the smallest endpoint
            A[i][1] > B[j][1] ? j++: i++;
        }
        
        
        return result;
        
    }
};
