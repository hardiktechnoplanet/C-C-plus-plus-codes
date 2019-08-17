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
 
// Time complexity: O(n)
class Solution {
public:
    bool isValidBSTHelper(TreeNode* node, TreeNode* lft=NULL, TreeNode* rgt=NULL)
    {
        //base cases
        if(node==NULL)
        {
            return true;
        }
        //node's val can not be <=node->left->val in BST
        if(lft!=NULL && node->val<=lft->val)
        {
            return false;
        }
        ////node's val can not be >=node->right->val in BST
        if(rgt!=NULL && node->val>=rgt->val)
        {
            return false;
        }
        
        // recursion
        // check recursively for every node. 
        return isValidBSTHelper(node->left,lft,node) and
        isValidBSTHelper(node->right,node,rgt);
        
    }
    bool isValidBST(TreeNode* root) {
        //empty tree is valid binary tree
        //call the helper function
        return isValidBSTHelper(root,NULL,NULL);
        
    }
};
int main(int argc, char** argv) {
	return 0;
}
