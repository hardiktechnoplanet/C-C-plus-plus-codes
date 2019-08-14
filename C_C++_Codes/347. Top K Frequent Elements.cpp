#include <iostream>

/* fill all the elements with the frequencies in a map and then put top k in minHeap. From minHeap
put them in vector.
Time Complexity: O(nlogk)
The complexity of Counter method is O(N). To build a heap and output list takes O(Nlog(k)). 
Hence the overall complexity of the algorithm is =O(Nlog(k)).

Space complexity :O(N) to store the hash map.
*/

vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map <int,int> elements;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        vector <int> result;
        
        //put every element in the map
		for(size_t i=0;i<nums.size();++i)
        {
            elements[nums[i]]++;
        }
        
        //put top k elements in the minHeap
        for(auto it:elements)
        {
            minHeap.push({it.second,it.first});
            if(minHeap.size()>k)
            {
                minHeap.pop();
            }
        }
        
        while(!minHeap.empty())
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
    
int main(int argc, char** argv) {
	return 0;
}
