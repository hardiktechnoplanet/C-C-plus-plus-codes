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
//https://www.youtube.com/watch?v=bNgfwQspr10
//call stack is also explanied in the video
/*
class Solution {
public:
    int sumNumbers(TreeNode* root) 
    {
        //test case
        if(root==NULL)
            return 0;
        return helper(root,0);
    }
    
    int helper(TreeNode *root, int pathSum)
    {
        //base case
        if(root==NULL)
            return 0;
        
        pathSum=pathSum*10 + root->val;
        //if it is a leaf node, return the pathSum
        if(root->left==NULL && root->right==NULL)
            return pathSum;
        
        return helper(root->left,pathSum)+helper(root->right,pathSum);
    }
};
*/

//Solution 2: Iterative
class Solution {
public:
    int sumNumbers(TreeNode* root) 
    {
        //test case
        if(root==NULL)
            return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,root->val});
        int sum=0;
        
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();
            TreeNode* node=curr.first;
            int val=curr.second;
            
            //if leaf node
            if(node->left==NULL && node->right==NULL)
                sum+=val;
            
            if(node->left)
                q.push({node->left,val*10 + node->left->val});
            if(node->right)
                q.push({node->right,val*10 + node->right->val});
        }
        return sum;
    }
    
};
