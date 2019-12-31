/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*Solution 1: Recursion

Complexity Analysis

Time complexity : we visit each node exactly once, thus the time 
complexity is O(N), where N is the number of nodes.

Space complexity : in the worst case, the tree is completely unbalanced, e.g. each node has
only one child node, the recursion call would occur N times (the height of the tree), therefore
the storage to keep the call stack would be O(N). But in the best case (the tree is completely balanced), 
the height of the tree would be log(N). Therefore, the space complexity in this case would be O(log(N)).*/

/*class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) 
    {
        //base case
        //we have reached to the end of the tree and we haven't
        //found the required sum
        if(root==NULL)
            return false;
        
        //check the case when we have actually found the path
        //if leaf node
        else if(root->left==NULL && root->right==NULL && root->val==sum)
            return true;
        
        else
            return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
        
    }
};*/


/*Solution 2: Iteration (DFS would work better than BFS)

Complexity Analysis

Time complexity : the same as the recursion approach O(N).
Space complexity : O(N) since in the worst case, when the tree is completely unbalanced, 
e.g. each node has only one child node, we would keep all N nodes in the stack. But in the 
best case (the tree is balanced), the height of the tree would be log(N). Therefore, the space 
complexity in this case would be O(log(N)).*/

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) 
    {
        //test case
        if(root==NULL)
            return false;
        
        //stack with node and sum so far
        stack<pair<TreeNode*,int>> st;
        st.push({root,root->val});
        
        while(!st.empty())
        {
            auto curr=st.top();
            st.pop();
            
            TreeNode* node=curr.first;
            int sumSoFar=curr.second;
            
            //check if the node is a leaf node and we have got the desired sum
            if(node->left==NULL && node->right==NULL)
            {
                if(sumSoFar==sum)
                    return true;
            }
            
            if(node->left)
                st.push({node->left, sumSoFar+node->left->val});
            
            
            if(node->right)
                st.push({node->right, sumSoFar+node->right->val});
        }
        return false;
    }
};
