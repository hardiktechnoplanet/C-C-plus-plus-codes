/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Iterative Sol, O(n) Time Complexity, O(h) space complexity
//https://www.youtube.com/watch?v=nzmtCFNae9k
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        if(root==NULL)
        {
            return result;
        }
        
        stack<TreeNode*> s;
        while(true)
        {
            if(root!=NULL)
            {
                s.push(root);
                root=root->left;
            }
            else
            {
                if(s.empty())
                    break;
                
                root=s.top();
                s.pop();
                result.push_back(root->val);
                root=root->right;
            }
        }
        return result;
    }
};
/* recursive solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        helper(root,result);
        return result;
    }
    void helper(TreeNode* node, vector<int>& result)
    {
        //base case
        if(node==NULL)
        {
            return;
        }
        helper(node->left,result);
        result.push_back(node->val);
        helper(node->right,result);
    }
};*/
