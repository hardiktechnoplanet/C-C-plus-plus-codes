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
    void flatten(TreeNode* root) 
    {
        if(root!=NULL)
        {
            //this is a dfs problem, so use a stack
            stack<TreeNode*> st;
            //push the root
            st.push(root);

            //traverse through the tree
            while(!st.empty())
            {
                TreeNode* currNode=st.top();
                st.pop();
                
                //we need to process the left node first and we are using
                //stack, so push the right node first (LIFO)

                //push the right child
                if(currNode->right)
                {
                    st.push(currNode->right);
                }
                //push the left child
                if(currNode->left)
                {
                    st.push(currNode->left);
                }

                if(!st.empty())
                {
                    currNode->right=st.top();
                }
                currNode->left=NULL;
            }
        }
       
        
        
        }
        
        
        
    
};
