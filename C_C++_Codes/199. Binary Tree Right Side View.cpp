/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Right side view: we need to check at every level=>BFS
//Time complexity: O(n), space complexity: O(n)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
	{
        
        vector<int> result;
        if(root==NULL)
        {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        //process the entire tree
        while(!q.empty())
        {
            //number of nodes in the current level
            int size=q.size();
            //process through all the nodes in current level
            for(int i=0;i<size;++i)
            {
                //to process each node, pop it from the queue
                TreeNode* current=q.front();
                q.pop();
                
                //if this the last element in the queue=>last element
                //on this level
                if(i==size-1)
                {
                    result.push_back(current->val);
                }
                if(current->left)
                {
                    q.push(current->left);
                }
                if(current->right)
                {
                    q.push(current->right);
                }
            }
        }
        return result;      
    }
};
