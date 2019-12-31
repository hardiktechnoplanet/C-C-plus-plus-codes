/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*Both Time and Space Complexity: O(n)*/
class Solution {
public:
    int minDepth(TreeNode* root) 
    {
        //base case
        if(root==NULL)
            return 0;
        
        //leaf node
        if(root->left==NULL && root->right==NULL)
            return 1;
        
        int min_Depth=INT_MAX;
        
        if(root->left)
            min_Depth=min(minDepth(root->left),min_Depth);
        
        if(root->right)
            min_Depth=min(minDepth(root->right),min_Depth);
        
        return min_Depth+1;
        
    }
};
