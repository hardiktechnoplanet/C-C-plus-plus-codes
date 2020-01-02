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
    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelper(root->left,root->right);
    }
    
    bool isSymmetricHelper(TreeNode* left, TreeNode* right)
    {
        if(left==NULL and right==NULL)
            return true;
        
        if(left->val!=right->val)
            return false;
        
        return isSymmetricHelper(left->left,right->right)&&
            isSymmetricHelper(left->right,right->left);
       // return false;
    }
};*/

//Solution 2: check leetcode solution
class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        //test case
        if(root==NULL)
            return true;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* t1=q.front();
            q.pop();
            TreeNode* t2=q.front();
            q.pop();
            
            if(t1==NULL && t2==NULL)
                continue;
            else if(t1==NULL || t2==NULL)
                return false;
            else if(t1->val!=t2->val)
                return false;
            
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
    
    
};
