//A greedy approach will work here. Always take the cheapest operation possible, 
//because the earlier a stick is combined, the more often its length will factor into the total cost.

class Solution {
public:
    int connectSticks(vector<int>& sticks) 
    {
        int result=0;
        //test case
        if(sticks.size()==0)
            return result;
        
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(size_t i=0;i<sticks.size();++i)
        {
            minHeap.push(sticks[i]);
        }
        while(minHeap.size()>1)
        {
            int a=minHeap.top();
            minHeap.pop();
            int b=minHeap.top();
            minHeap.pop();
            result+=a+b;
            minHeap.push(a+b);
        }
        return result;
        
    }
};
