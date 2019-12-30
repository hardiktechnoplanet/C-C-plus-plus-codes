//https://www.youtube.com/watch?v=PZYTs9y4f4o
//Time and Space Complexity: O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*Array is sorted in ascending order => middle element will be the root*/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        //test case
        if(nums.empty())
            return NULL;
        
        return helper(nums,0, nums.size()-1);
    }
    
    TreeNode* helper(vector<int>& nums, int left, int right)
    {
        //base case
        if(left>right)
            return NULL;
        
        //the middle element will be the root
        int middle=left+(right-left)/2;
        TreeNode* root=new TreeNode(nums[middle]);
        
        //elements from left to middle-1 will be in the left subtree
        root->left=helper(nums,left, middle-1);
        //elements from middle+1 to right will be in the right subtree
        root->right=helper(nums,middle+1,right);
        
        return root;
    }
};
