//https://www.youtube.com/watch?v=CE2b_-XfVDk&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=7
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if(nums.size()==0)
            return 0;
        int maxVal=0;
        
        //at every position, the longest increasing subsequence is of size at least 1,
        //hence, initialize the vector with value 1
        vector<int> T(nums.size(),1);
        for(size_t i=1;i<nums.size();++i)
        {
            for(size_t j=0;j<=i;++j)
            {
                //if nums[j]<nums[i]=>the longest subsequence at i is atleast
                //be the longest increasing subsequence at j+1
                if(nums[j]<nums[i])
                {
                    T[i]=max(T[i],T[j]+1);
                }
                //else: do nothing
            }
        }
        //get the max value in T
        for(size_t i=0;i<T.size();++i)
        {
            if(T[i]>maxVal)
            {
                maxVal=T[i];
            }
        }
        
        return maxVal;
        
    }
};
