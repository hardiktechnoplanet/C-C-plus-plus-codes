class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        vector<int> rows(matrix.size());
        vector<int> cols(matrix[0].size());
        
        //mark the rows and columns that are to be made zero
        for(size_t i=0;i<matrix.size();++i)
        {
            for(size_t j=0;j<matrix[0].size();++j)
            {
                if(matrix[i][j]==0)
                {
                    rows[i]=1;;
                    cols[j]=1;;
                }
            }
        }
        // Iterate over the array once again and using the rows and cols sets, update the elements.
        for(size_t i=0;i<rows.size();++i)
        {
            for(size_t j=0;j<cols.size();++j)
            {
                if(rows[i]==1 || cols[j]==1)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};
