#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Time complexity: O(n), space complexity: O(n) (function calls will be stacked)
class Solution {
public:
    bool isSymmetricHelper(TreeNode* left, TreeNode* right)
    {
        //base cases
        //if left or rigt node is NULL, for symmetric tree, they both should
        // be NULL
        if(left==NULL || right==NULL)
        {
            return left==right;
        }
        //left node val should be same as right node val
        if(left->val!=right->val)
        {
            return false;
        }
        
        //recursion
        // tree to be symmetrics, left subtree of left node should be same as
        //right subtree of right node and right subtree of left node should be
        //same as left subtree of right node
        return isSymmetricHelper(left->left,right->right) && 
            isSymmetricHelper(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        //if root is NULL, the tree is kind of symmetric
        if(root==NULL)
        {
            return true;
        }
        return isSymmetricHelper(root->left,root->right);
        
    }
};
int main(int argc, char** argv) {
	return 0;
}
