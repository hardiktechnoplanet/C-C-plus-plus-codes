/*class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        vector<int> res;
        if(nums.size()==1)
        {
            res.push_back(nums[0]);
            return res;
        }
        int n=nums.size()/3;
        unordered_map<int,int> hash;
        vector<int>::iterator it;
        for(size_t i=0;i<nums.size();++i)
        {
            if((hash[nums[i]]+1>n))
            {
                it=find(res.begin(),res.end(),nums[i]);
                if(it==res.end())
                    res.push_back(nums[i]);
            }
            hash[nums[i]]++;
            //else
                //hash[nums[i]]++;
        }
        return res;
        
    }
};*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        
        vector<int>res;
       int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
       for(auto n: nums)
       {
           if(candidate1 == n) 
               count1++;
           else if(candidate2 == n)
               count2++;
           else if(count1 == 0){
               candidate1 = n;
               count1 = 1;
           }
           else if(count2 == 0){
               candidate2 = n;
               count2 = 1;
           }
           else{
               count1--;
               count2--;
           }
       }
       count1 = 0;
       count2 = 0;
       for(auto n: nums)
           if(candidate1 == n)
               count1++;
           else if(candidate2 == n)
               count2++;
       if(count1 > nums.size()/3)
           res.push_back(candidate1);
       if(count2 > nums.size()/3)
           res.push_back(candidate2);
       return res;
        
    }
};
