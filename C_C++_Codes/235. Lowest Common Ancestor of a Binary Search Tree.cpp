/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*Solution 1: Recursive: Time and Space Complexity: O(n)
For example tree, see the video below
https://www.youtube.com/watch?v=TIoCCStdiFo*/
/*class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        //if the root val is < p and q, we need to search in right sub tree of root
        if(root->val< p->val && root->val < q->val)
            return lowestCommonAncestor(root->right,p,q);
        
        //if the root val is > p and q, we need to search in left sub tree of root
        else if(root->val> p->val && root->val > q->val)
            return lowestCommonAncestor(root->left,p,q);
        
        //we have found the split point 
        else
            return root;
        
    }
};*/

//Solution 2: Iterative: Time Complexity: O(n), Space Complexity: O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        //start from the root node
        TreeNode* node=root;
        
        //traverse the tree
        while(node!=NULL)
        {
            //value of the parent node
            int parentVal=node->val;
            
            if(parentVal<p->val && parentVal<q->val)
                node=node->right;
            else if(parentVal>p->val && parentVal>q->val)
                node=node->left;
            else
                return node;
        }
        return NULL;
    }
};
