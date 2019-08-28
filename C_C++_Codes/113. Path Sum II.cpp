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
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int>> result;
        vector<int> path;
        //test case
        if(root==NULL)
            return result;
        
        dfsHelper(root,result,path,0,sum);
        return result;
    }
    void dfsHelper(TreeNode* root,vector<vector<int>>& result, vector<int> path,int sum,int target)
    {
        //base case
        //if we reach at the end of the tree and sum is
        //not found
        if(root==NULL)
            return;
        
        //if the above condition is not true
        path.push_back(root->val);
        sum+=root->val;
        
        //check if we are at the leaf node and the sum so far=target
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==target)
            {
                result.push_back(path);
                //path.clear();
            }
            return;
        }
        
        //recursion
        dfsHelper(root->left,result,path,sum,target);
        dfsHelper(root->right,result,path,sum,target);
    }
};
