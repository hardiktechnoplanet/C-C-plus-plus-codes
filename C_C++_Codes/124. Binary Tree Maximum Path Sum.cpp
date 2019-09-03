/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* let's simplify the problem and implement a function maxGain(node) which takes a node as an argument and computes a maximum contribution that this node and one/zero of its subtrees could add.
That means that we need to check at each step what is better : to continue the current path or to start a new path with the current node as a highest node in this new path.*/
//O(n)
class Solution {
public:
    int maxSum=INT_MIN;
    int maxPathSum(TreeNode* root) 
    {
        maxGain(root);
        return maxSum;
    }
    
    int maxGain(TreeNode* node)
    {
        //base case
        if(node==NULL)
        {
            return 0;
        }
        
        //max sum on the left and right sub-trees of node
        int leftGain=max(maxGain(node->left),0);
        int rightGain=max(maxGain(node->right),0);
        
        //the price to start a new path where 'node' is a
        //highest node
        int priceNewPath=node->val+leftGain+rightGain;
        
        //update the maxSum if it is better to start a new path
        maxSum=max(maxSum,priceNewPath);
        
        //recursion
        //return the max gain if continue the same path 
        return node->val +  max(leftGain, rightGain);
    }
};
