#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int missingNumber(vector<int>& nums) {
        int length=nums.size();
        
        // store all the elements from nums into a set. Set contains only the distinct elements and elements can be               //traversed in sorted order. So, the first missing number is set is our result 
        
        set<int> res;
        
        int result;
        
        //insert all the numbers in set
        for(int num:nums)
        {
            res.insert(num);
        }
        //traverse through the set to find the first missing number
        for(size_t i=0;i<res.size()+1;++i)
        {
            if(res.find(i)==res.end())
            return i;
        }
        //if all the numbers are in set, return -1
        return -1;
        
    }

