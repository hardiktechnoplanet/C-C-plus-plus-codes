/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) 
    {
        //base case
        //we have reached to the end of the tree and we haven't
        //found the required sum
        if(root==NULL)
            return false;
        
        //check the case when we have actually found the path
        //if leaf node
        else if(root->left==NULL && root->right==NULL && root->val==sum)
            return true;
        
        else
            return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
        
    }
};
