//Solution1: Iterative
//Time Complexity: O(n)
class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int lastPos = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= lastPos) 
            {
                cout<<"i: "<<i<<endl;
                lastPos = i;
                cout<<"lastPos: "<<lastPos<<endl;
            }
        }
        return lastPos == 0;
    }
};

/*
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int distance = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            distance = max(distance, i + nums[i]);
            if(distance == i) return false;
        }
        return true;
    }
};
*/
/*
//Time Complexity: 2^n
Solution2: back tracking
class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        return canJumpHelper(nums,0);
    }
    
    bool canJumpHelper(vector<int>& nums,int position)
    {
        //base case
        //when we are at the last position
        if(position==nums.size()-1)
        {
            return true;
        }
        
        int size=nums.size()-1;
        int furthestJump=min(position+nums[position],size);
        for(int nextPosition=position+1;nextPosition<=furthestJump;nextPosition++)
        {
            if(canJumpHelper(nums,nextPosition))
            {
                return true;
            }
        }
        return false;
    }
};
*/

/*
//Time Complexity: O(n^2)
//Solution3: DP
class Solution {
enum Index{
        GOOD, BAD, UNKNOWN
    };
public:
    bool canJump(vector<int>& nums) 
    {
        //for memorization
        vector<Index> memory(nums.size(),UNKNOWN);
        memory[nums.size()-1]=Index.GOOD;
        return canJumpHelper(nums,0,memory);
    }
    
    bool canJumpHelper(vector<int>& nums,int position,vector<Index>& memory)
    {
        //base case
        //when we are at the last position
        if(memory[position]!=UNKNOWN)
        {
            return memory[position]==Index.GOOD ? true : false;
        }
        
        int size=nums.size()-1;
        int furthestJump=min(position+nums[position],size);
        for(int nextPosition=position+1;nextPosition<=furthestJump;nextPosition++)
        {
            if(canJumpHelper(nums,nextPosition,memory))
            {
                memory[position]=Index.GOOD;
                return true;
            }
        }
        memory[position]=Index.BAD;
        return false;
    }
};*/
