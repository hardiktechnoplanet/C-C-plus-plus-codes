/* https://www.youtube.com/watch?v=LU4fGD-fgJQ&list=PLiQ766zSC5jND9vxch5-zT7GuMigiWaV_&index=7 
https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
An empty tree is height-balanced. A non-empty binary tree T is balanced if:
1) Left subtree of T is balanced
2) Right subtree of T is balanced
3) The difference between heights of left subtree and right subtree is not more than 1.*/

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
    bool isBalanced(TreeNode* root) 
    {
        //base case
        if(root==NULL)
            return true;
        
        int leftHeight=0,rightHeight=0;
        
        //Get the height of left and right sub trees
        leftHeight=getHeight(root->left);
        rightHeight=getHeight(root->right);
        
        if(abs(leftHeight-rightHeight)<=1 && isBalanced(root->left) && isBalanced(root->right))
        {
            return true;
        }
        //If we reach here then tree is not height-balanced
        return false;
    }
    
    //this function Compute the "height" of a tree. Height is the number of  
    //nodes along the longest path from the root node down to the farthest leaf node
    int getHeight(TreeNode* node)
    {
        //base case: empty tree
        if(node==NULL)
            return 0;
        
        //If tree is not empty then height = 1 + max of left height and right heights
        int height=1+ max(getHeight(node->left),getHeight(node->right));
        return height;
    }
};
