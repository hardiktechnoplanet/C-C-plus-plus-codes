//Solution 1: Binary search
//https://www.youtube.com/watch?v=CFgUQUL7j_c
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int left=0, right=nums.size()-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            
            //go the right sub array
            if(nums[mid]<nums[mid+1])
                left=mid+1;
            else
                right=mid;
        }
        return left;
    }
};

/*class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int peak=0;
        if(nums.size()==1)
        {
            return peak;
        }
        for(size_t i=0;i<nums.size();++i)
        {
            //first element
            if(i==0)
            {
                if(nums[i]>nums[i+1])
                {
                    peak=i;
                    return peak;
                }
            }
            //last element
            else if(i==nums.size()-1)
            {
                if(nums[i]>nums[i-1])
                {
                    peak=i;
                    return peak;
                }
            }
            //rest of the elements
            else
            {
                 if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
                 {
                     peak=i;
                     return peak;
                 }
                
            }
           
        }
        return peak;
    }
};*/
