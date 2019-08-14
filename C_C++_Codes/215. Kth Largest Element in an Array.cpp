#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* Solution1: sort the array and find the Kth element from the end- O(NlogN), space-O(1)
   Soution2: minHeap: O(NlogK), space: O(k)
   Solution3: QuickSelect: O(N), space: O(1)*/
   
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	
    	//copy the first k-1 elements in the minHeap. Later, if new element is greater than minHeap.top(), 
    	//replace it, else leave it. At the end, Kth largest element will be at the top of the minHeap
        priority_queue <int, vector<int>, greater<int>>seen;
        int res=0;
        for(size_t i=0;i<nums.size();++i)
        {
            if(seen.size()<k)
            {
                seen.push(nums[i]);
            }
            else
            {
                if(nums[i]>seen.top())
                {
                    seen.pop();
                    seen.push(nums[i]);
                }
            }
        }
        
        res=seen.top();
        return res;
        
    }
};
int main(int argc, char** argv) {
	return 0;
}
