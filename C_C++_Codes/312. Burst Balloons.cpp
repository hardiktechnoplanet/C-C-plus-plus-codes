//Bottom up DP: https://www.youtube.com/watch?v=IFNibRVgFBo
class Solution {
public:
    int maxCoins(vector<int>& nums) 
    {
        //test case
        if(nums.size()==0)
            return 0;
        
        int size=nums.size();
        //memory
        vector<vector<int>> T (size, vector<int>(size,0));
        
        //we will check all the sub arrays of all the possible lengths
        for(int len=1; len<=size; ++len)
        {
            for(int i=0; i<=size-len; ++i)
            {
                int j=i+len-1;
                
                //k indicates which balloon should burst last, so, we will try every balloon from i to j as k
                //to check which balloon should be bursted at last such that we will get the max value
                for(int k=i; k<=j; ++k)
                {
                    //initially the leftValue and rightValue is 1. If there is any element on 
                    //the left or right of k, then leftValue and rightValue will take that value
                    int leftValue=1;
                    int rightValue=1;
                    
                    if(i!=0)
                    {
                        leftValue=nums[i-1];
                    }
                    if(j!=nums.size()-1)
                    {
                        rightValue=nums[j+1];
                    }
                    
                    //before is initially 0. If k is i then before will
                    //stay 0 otherwise it gets value T[i][k-1]
                    //after is similarly 0 initially. if k is j then after will
                    //stay 0 other will get value T[k+1][j]
                    int before=0;
                    int after=0;
                    
                    if(i!=k)
                    {
                        before=T[i][k-1];
                    }
                    if(j!=k)
                    {
                        after=T[k+1][j];
                    }
                    
                    T[i][j]=max(leftValue*nums[k]*rightValue + before +after, T[i][j]);
                    
                }
            }
        }
        return T[0][size-1];
    }
};
