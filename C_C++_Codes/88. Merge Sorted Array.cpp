/*Push both the array values in priority_queue. Now, pop the pq and push the values in nums1 (it will be in increasing order)
Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        /*priority_queue<int,vector<int>,greater<int>> minHeap;
        int i=0;
        //push the nums1 vector in minHeap
        while(i<m)
        {
            minHeap.push(nums1[i]);
            i++;
        }
        i=0;
        //push the nums2 vector in minHeap
        while(i<n)
        {
            minHeap.push(nums2[i]);
            i++;
        }
        
        i=0;
        //Pop the minHeap and put the elements in nums1
        while(minHeap.size()>0)
        {
            nums1[i]=minHeap.top();
            minHeap.pop();
            i++;
        }*/
        /*Start from the last index of 2 vectors. Whichever value is larger,
        put it at the last index of the first vector.
        Time Complexity: O(n)
        Space Complexity: O(n) */
        int n1=m-1,n2=n-1,n3=nums1.size()-1;
        while(n1>=0 && n2>=0)
        {
            if(nums2[n2]>nums1[n1])
            {
                nums1[n3]=nums2[n2];
                n2--;
            }
            else 
            {
                nums1[n3]=nums1[n1];
                n1--;
            }
            n3--;
        }
        
        while(n2>=0)
        {
            nums1[n3]=nums2[n2];
            n2--;
            n3--;
        }
        
    }
};
