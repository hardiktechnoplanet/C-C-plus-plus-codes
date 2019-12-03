/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//https://www.youtube.com/watch?v=j16cwbLEf9w

//If we perform level order traversal and we hit the first NULL node, we should not
//get any node after that. In the level order, we first find the left node, so if
//this node is NULL and we get some node after that, it means that left is null and we
//have some node in right. This is not a complete tree
class Solution {
public:
    bool isCompleteTree(TreeNode* root) 
    {
        //test case
        if(root==NULL)
            return true;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool lastNode=false;
        
        while(!q.empty())
        {
            TreeNode* currNode=q.front();
            q.pop();
            
            //if this is a NULL node, this should be the last node
            if(currNode==NULL)
                lastNode=true;
            else
            {
                //if we have already seen a NULL node before this node
                //the tree is not complete
                if(lastNode)
                    return false;
                
                //else perform the level order traversal
                else
                {
                    q.push(currNode->left);
                    q.push(currNode->right);
                }
            }
        }
        return true;
        
    }
};
