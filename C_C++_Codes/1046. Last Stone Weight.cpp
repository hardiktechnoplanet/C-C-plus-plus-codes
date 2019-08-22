/* Make a priority queue from the stones vector. Heap will sort the order.
Loop through the heap till there are 2 elements in it
the first 2 elements are the biggest 2, subtract the first
from second. If the result>0, push it back in the heap. 
Return the heap.top if heap is not empty. If empty, return 0*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        //test case
        if(stones.empty())
        {
            return 0;
        }
        
        //make a priority queue (heap) from the stones vector
        priority_queue<int> heap (stones.begin(),stones.end());
        
        //loop through the heap till there are 2 elements in it
        //the first 2 elements are the biggest 2, subtract the first
        //from second. If the result>0, push it back in the heap
        while(heap.size()>1)
        {
            int stone1=heap.top();
            heap.pop();
            int stone2=heap.top();
            heap.pop();
            stone1 -=stone2;
            
            if(stone1)
            {
                heap.push(stone1);
            }
        }
        
        //return the heap top if heap is not empty
        if(heap.empty())
            return 0;
        return heap.top();        
    }
};
