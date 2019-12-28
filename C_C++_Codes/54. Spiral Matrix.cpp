//Solution 1: one iteration (see leetcode solution)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) 
    {
        //test case
        if(mat.empty())
            return {};
        
        int r=mat.size(), c=mat[0].size();
        vector<int> result(r*c,0);
        
        //visited vector
        vector<vector<bool>> visited (r,vector<bool>(c,false));
        
        //direction vectors (rigth, down, left, up -> spiral order)
        vector<int> dr={0, 1, 0,-1};
        vector<int> dc={1, 0, -1, 0};
        
        int row=0, col=0, dir=0;
        for(size_t i=0;i<r*c;++i)
        {
            result[i]=(mat[row][col]);
            visited[row][col]=true;
            
            int next_row=row+dr[dir];
            int next_col=col+dc[dir];
            
            //check for bounds
            if(next_row>=0 && next_row<r && next_col>=0 && 
               next_col<c && visited[next_row][next_col]==false)
            {
                row=next_row;
                col=next_col;
            }
            else
            {
                //if out of bound=>change the direction
                dir=(dir+1)%4;
                row+=dr[dir];
                col+=dc[dir];
            }
        }
        return result;
    }
};


/*
//Solution2: Layer by layer: 4 iterations (slower than solution 1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        
        if(mat.empty())
        {
            return {};
        }
    vector<int> result;	
    int m=mat.size();
    int n=mat[0].size();
    int k=0; //starting index of row
	int l=0; //starting index of column
	int i;

	while(l<n && k<m)
	{
		//print the first row from the remaining rows
		for(i=l;i<n;i++)
		{
			result.push_back(mat[k][i]);
		}
		k++;
		
		//print the last columns from the remaining columns
		for(i=k;i<m;i++)
		{
			result.push_back(mat[i][n-1]);
		}
		n--;
		
		//print the last row from the remaining rows
		if(k<m)
		{
			for(i=n-1;i>=l;i--)
			{
				result.push_back(mat[m-1][i]);
			}
			m--;
		}
		
		//print the first column from the remaining columns
		if(l<n)
		{
			for(i=m-1;i>=k;i--)
			{
				result.push_back(mat[i][l]);
			}
			l++;
		}
	}
        return result;
    }
};*/
