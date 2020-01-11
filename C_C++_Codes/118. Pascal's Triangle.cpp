class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        //test case
        if(numRows==0) 
            return vector<vector<int> >();
        
        vector<vector<int>> result(numRows);
        
        // Iterate through every line
        for(int line=0;line<numRows;++line)
        {
            // Every line has number of integers  
            // equal to line number
            for(int i=0;i<=line;++i)
            {
                //first and last value in every row is 1
                if(line==i || i==0)
                {
                    result[line].push_back(1);
                }
                // Other values are sum of values just  
                // above and left of above
                else
                { 
                    result[line].push_back(result[line-1][i-1]+result[line-1][i]);
                }
            }
        }
        return result;
        
    }
};
/*class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        //test case
        if(numRows==0) 
            return vector<vector<int> >();
        
        vector<vector<int>> result(numRows, vector<int> (1,1));
        //first colum in result is filled with 1, so we dont have to 
        //fill the 0th row and 1st colum (for any row)
        
        //// Iterate through every line (except the 0th line)
        for(int line=1;line<numRows;++line)
        {
            // Every line has number of integers  
            // equal to line number
            for(int i=1;i<=line;++i)
            {
                //first and last value in every row is 1
                //we have already initialized every col with 1 
                //so we dont have to check for i==0
                if(line==i)// || i==0)
                {
                    result[line].push_back(1);
                }
                // Other values are sum of values just  
                // above and left of above
                else
                { 
                    result[line].push_back(result[line-1][i-1]+result[line-1][i]);
                }
            }
        }
        return result;
        
    }
};*/
