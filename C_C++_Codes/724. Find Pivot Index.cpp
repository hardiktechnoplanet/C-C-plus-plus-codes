/*Solution 1: Get the total sum of the array first. Then Iterate through the array and keep 
updating the left sum which is initialized as zero. In the loop, we can get the right sum by 
subtracting the elements one by one. 

1) Initialize leftsum  as 0
2) Get the total sum of the array as sum
3) Iterate through the array and for each index i, do following.
    a)  Update sum to get the right sum.  
           sum = sum - arr[i] 
       // sum is now right sum
    b) If leftsum is equal to sum, then return current index. 
       // update leftsum for next iteration.
    c) leftsum = leftsum + arr[i]
4) return -1 
// If we come out of loop without returning then
// there is no pivot index*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int sum=0,leftSum=0;
        //find the sum of the whole vector
        for(size_t i=0;i<nums.size();++i)
        {
            sum+=nums[i];
        }
        
        for(size_t i=0;i<nums.size();++i)
        {
            //right sum for index i
            sum-=nums[i];
            
            if(leftSum==sum)
                return i;
            
            //update the left sum
            leftSum+=nums[i];
        }
        return -1;
        
    }
};

/*Solution 2: Use two loops. Outer loop iterates through all the element and inner loop
finds out whether the current index picked by the outer loop is pivot index or not. 
Time complexity of this solution is O(n^2).*/

/*
class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    { 
        int leftsum, rightsum; 

        //Check for indexes one by one until  
        an equilibrium index is found 
        for (size_t i = 0; i < nums.size(); ++i)  
        {      

            //get left sum 
            leftsum = 0;  
            for (size_t j = 0; j < i; j++) 
                leftsum += nums[j]; 

            // get right sum 
            rightsum = 0;  
            for (size_t j = i + 1; j < nums.size(); j++) 
                rightsum += nums[j]; 

            // if leftsum and rightsum   
            //are same, then we are done
            if (leftsum == rightsum) 
                return i; 
        } 

        //return -1 if no pivot  
        //index is found
        return -1;
        
    }
};
*/
