/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//https://www.youtube.com/watch?v=bNgfwQspr10
//call stack is also explanied in the video
class Solution {
public:
    int sumNumbers(TreeNode* root) 
    {
        //test case
        if(root==NULL)
            return 0;
        return helper(root,0);
    }
    
    int helper(TreeNode *root, int pathSum)
    {
        //base case
        if(root==NULL)
            return 0;
        
        pathSum=pathSum*10 + root->val;
        //if it is a leaf node, return the pathSum
        if(root->left==NULL && root->right==NULL)
            return pathSum;
        
        return helper(root->left,pathSum)+helper(root->right,pathSum);
    }
};
