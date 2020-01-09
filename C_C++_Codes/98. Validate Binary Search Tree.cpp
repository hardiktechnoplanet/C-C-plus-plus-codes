/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Solution 1: Recursive
/*class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        return isValidBSTHelper(root,NULL,NULL);
    }
    bool isValidBSTHelper(TreeNode* node,TreeNode* lft,TreeNode* rgt)
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
        //while going to left, the nodes->left value should be > lft(min) and < nodes value(max)
        return isValidBSTHelper(node->left,lft,node) and
            
        //while going to right, the nodes->right value should be > node's value(min) and < rgt (max)
        isValidBSTHelper(node->right,node,rgt);
    }
};
*/
//Solution 2: Iterative: the inorder traversal should be in sorted order
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        stack<TreeNode*> st;
        TreeNode* curr=root;
        TreeNode* prev=NULL;
        
        while(curr!=NULL || !st.empty())
        {
            if(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            else
            {
                if(!st.empty())
                {
                    curr=st.top();
                    st.pop();
                }
                if(prev!=NULL && curr->val <=prev->val)
                    return false;
                prev=curr;
                curr=curr->right;
            }
        }
        return true;
    }
};
