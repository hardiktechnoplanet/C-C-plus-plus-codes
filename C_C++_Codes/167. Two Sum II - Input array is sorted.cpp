//Time and Space Complexity: O(n), two pointers approach
class Solution {
public:
    vector<int> twoSum(vector<int>& array, int target) {
        
        vector<int> result;
        int start=0,end=array.size()-1;
        
        while(start<end)
        {
            int sum=array[start]+array[end];
            if(sum==target)
            {
                //result.push_back(start+1);
                //result.push_back(end+1);
                result={start+1,end+1};
                return result;
            }
            else if(sum<target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return {-1,-1};
        
    }
};
