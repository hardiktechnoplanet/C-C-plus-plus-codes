/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//https://www.youtube.com/watch?v=elQcrJrfObg
//https://www.youtube.com/watch?v=BHB0B1jFKQc
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        //test case
        if(root==NULL)
            return result;
        
        stack<TreeNode*>st;
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode* currNode=st.top();
            //Preorder is N L R, we are at the node, so, 
            //push it in the result vector
            result.push_back(currNode->val);
            st.pop();
            
            //Preorder is N L R, we need to go to the left of the node,
            //stack is LIFO, so we first need to push right child into stack before
            //pushing left child so that in next iteration we can visit left child first.
            if(currNode->right)
                st.push(currNode->right);
            if(currNode->left)
                st.push(currNode->left);
            
        }
        return result;
        
    }
};
