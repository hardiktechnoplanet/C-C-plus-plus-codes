//DP: https://www.youtube.com/watch?v=NnD96abizww&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=2
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int maxVal=0;
        int m=text1.length(); int n=text2.length();
        vector<vector<int>> data(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<data.size();++i)
        {
            for(int j=1;j<data[i].size();++j)
            {
                //Case I: if both the chars are same, we know that
                //the max lenght will be equal to max length when
                //we dont consider these 2 chars +1 (this 1 is contributed
                //by these 2 chars) 
                if(text1[i-1]==text2[j-1])
                {
                    data[i][j]=data[i-1][j-1]+1;
                }
                //Case II: if both the chars are not same, the max len will
                //be the max len when we exclude char from string 1 and char
                //from string 2
                else
                {
                    data[i][j]=max(data[i-1][j],data[i][j-1]);
                }
            }
        }
        return data[m][n];
        
    }
};
