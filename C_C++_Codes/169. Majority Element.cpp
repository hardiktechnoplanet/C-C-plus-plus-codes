/*class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int res=0;
        if(nums.size()==1)
            return nums[0];
        
        unordered_map<int,int> hash;
        for(size_t i=0;i<nums.size();++i)
        {
            if((hash.find(nums[i])!=hash.end()) && (hash[nums[i]]+1>nums.size()/2))
            {
                res=nums[i];
                break;
            }
            else
                hash[nums[i]]++;
        }
        return res;
    }
};
*/

/*https://www.geeksforgeeks.org/majority-element/
Using Moore’s Voting Algorithm: O(n):time complexity, O(1): space complexity.
The algorithm for first phase that works in O(n) is known as Moore’s Voting Algorithm. 
Basic idea of the algorithm is that if we cancel out each occurrence of an element e with all 
the other elements that are different from e then e will exist till end if it is a majority element.
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int res=0;
        if(nums.size()==1)
            return nums[0];
        
        int size=nums.size();
        int maj_index = 0, count = 1; 
        for (int i = 1; i < size; i++) 
        { 
            if (nums[maj_index] == nums[i]) 
                count++; 
            else
                count--; 
            if (count == 0) 
            { 
                maj_index = i; 
                count = 1; 
            } 
        } 
        return nums[maj_index]; 
    }
};
