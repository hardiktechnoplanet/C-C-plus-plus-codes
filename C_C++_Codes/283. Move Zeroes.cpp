/*First put all the non zero elements in the array and then from the last non zero
element index to the size of the array, there should be 0's only*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        //first fill all the non zero elements
        int lastNonZeroIndex=0;
        for(size_t i=0;i<nums.size();++i)
        {
            if(nums[i]!=0)
            {
                nums[lastNonZeroIndex]=nums[i];
                lastNonZeroIndex++;
            }
        }
        //Now, from the lastNonZeroIndex to nums.size(), there
        //should be zeros only
        for(size_t i=lastNonZeroIndex;i<nums.size();++i)
        {
            nums[i]=0;
        }
    }
    
};

/*Space Complexity : O(1)O(1). Only constant space is used.

Time Complexity: O(n)O(n). However, the total number of operations are optimal. The total operations (array writes) that code does is Number of non-0 elements.*/
/*
void moveZeroes(vector<int>& nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
}
*/
