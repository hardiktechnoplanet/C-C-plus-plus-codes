/*O(n+m)
we cans start either from lower left or upper right corners. Suppose we
start from lower left, if the target is < current element, we can move
right as the rows are sorted and if it is > current element, we can move
up as cols are sorted*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        //test case
        if(matrix.size()==0)
        {
            return false;
        }
        
        //start from the lowest left corner
        int cols=0;
        int rows=matrix.size()-1;
        
        //traverse with inbounds
        while(cols<matrix[0].size() && rows>=0)
        {
            if(matrix[rows][cols]==target)
            {
                return true;
            }
            else if(matrix[rows][cols]<target)
            {
                cols++;
            }
            else
            {
                rows--;
            }
        }
        return false;
        
    }
};
