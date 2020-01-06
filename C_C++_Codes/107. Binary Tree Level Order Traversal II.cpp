/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*Step 1: Find the max depth of the tree.
Step 2: Pass this max depth to levelOrder function, start filling the vector from
maxDepth level*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        //test case
        if(root==NULL)
            return vector<vector<int>>();
        
        //find the max depth (max level)
        int depth=findDepth(root);
         vector<vector<int>> result(depth);
        
        levelOrder(root,depth-1,result);
        return result;
        
    }
    
    int findDepth(TreeNode* node)
    {
        if(node==NULL)
            return 0;
        int leftDepth=findDepth(node->left);
        int rightDepth=findDepth(node->right);
        
        return 1+max(leftDepth,rightDepth);
        
    }
    
    void levelOrder(TreeNode* node, int level, vector<vector<int>>& result)
    {
        if(node==NULL)
            return;
        
        
        result[level].push_back(node->val);
        levelOrder(node->left,level-1,result);
        levelOrder(node->right,level-1,result);
    }
};
