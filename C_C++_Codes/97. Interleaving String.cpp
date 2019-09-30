//https://www.youtube.com/watch?v=ih2OZ9-M3OM&t=1s
class Solution {
public:
    bool isInterleave(string str1, string str2, string str3) 
    {
        
        int m=str1.length(), n=str2.length();
        //test case
        if(str1.length() + str2.length() != str3.length())
        {
            return false;
        }
        
        vector<vector<bool>> T (m + 1, vector<bool>(n + 1, false));
        
        for(int i=0; i < T.size(); i++)
        {
            for(int j=0; j < T[0].size(); j++)
            {
                int l = i + j -1;
                //T[0][0] should be true
                if(i == 0 && j == 0)
                {
                    T[i][j] = true;
                }
                //fill up the first column by taking the value at the top
                else if(i == 0)
                {
                    if(str3[l] == str2[j-1]){
                        T[i][j] = T[i][j-1];
                    }
                }
                //fill up the first row by taking value from the left
                else if(j == 0)
                {
                    if(str1[i-1] == str3[l]){
                        T[i][j] = T[i-1][j];
                    }
                }
                else
                {
                    /*if(str3[l]==str1[i-1])
                    {
                        //take the value from the left
                        T[i][j]=T[i-1][j];
                    }
                    else if (str3[l]==str2[j-1])
                    {
                        //take the value from the top
                        T[i][j]=T[i][j-1];
                    }
                    else
                    {
                        T[i][j]=false;
                    }*/
                    T[i][j] = (str1[i-1] == str3[l] ? T[i-1][j] : false) || (str2[j-1] == str3[l] ? T[i][j-1] : false);
                }
            }
        }
        return T[str1.size()][str2.size()];
        
    }
};
