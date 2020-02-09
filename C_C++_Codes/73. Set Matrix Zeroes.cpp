//Time Complexity: O(m*n), Space Complexity: O(m+n)
/*
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
*/

//Time Complexity: O(m*n), Space Complexity: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        bool isColZero=false;
        
        for(size_t i=0;i<matrix.size();++i)
        {
            if(matrix[i][0]==0)
                isColZero=true;
            for(size_t j=1;j<matrix[0].size();++j)
            {
                //if the current element is 0, make the first element in 
                //this row and column =0
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        //Iterate over the array once again and using the first row 
        //and first column, update the elements.
        for(size_t i=1;i<matrix.size();++i)
        {
            for(size_t j=1;j<matrix[0].size();++j)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }
        
        //check if the first row needs to be set to zero
        if(matrix[0][0]==0)
        {
            for(size_t i=0;i<matrix[0].size();++i)
                matrix[0][i]=0;
        }
        
        //check if the first col needs to be set to zero
        if(isColZero)
        {
            for(size_t i=0;i<matrix.size();++i)
                matrix[i][0]=0;
        }
    }
};
