//Solution 1:
//Time and Space Complexity: O(n)
/*class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int,int> hashMap;
        unordered_map<int,int>::iterator it;
        for(size_t i=0;i<nums.size();++i)
        {
            hashMap[nums[i]]++;
        }
        for(it=hashMap.begin();it!=hashMap.end();++it)
        {
            if(it->second==1)
                return it->first;
        }
        return 0;
    }
};*/

//Solution 2:
//Time Complexity: O(n) and Space Complexity: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int seen_once=0, seen_twice=0;
        for(size_t i=0;i<nums.size();++i)
        {
            seen_once=~seen_twice & (seen_once^nums[i]);
            seen_twice=~seen_once & (seen_twice^nums[i]);
        }
        return seen_once;
    }
};
