/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Solution 1: Recursive Solution
/*class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        //test case
        if(root==NULL)
            return NULL;
        
        TreeNode *left=invertTree(root->left);
        TreeNode *right=invertTree(root->right);
        
        root->left=right;
        root->right=left;
        return root;   
    }
};*/

//Solution 2: Iterative Solution
/*The idea is that we need to swap the left and right child of all nodes in the tree. So we create a queue to store nodes whose left and right child have not been swapped yet. Initially, only the root is in the queue. As long as the queue is not empty, remove the next node from the queue, swap its children, and add the children to the queue. Null nodes are not added to the queue. Eventually, the queue will be empty and all the children swapped, and we return the original root.*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        //test case
        if(root==NULL)
            return NULL;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode *currNode=q.front();
            q.pop();
            TreeNode *temp=currNode->left;
            currNode->left=currNode->right;
            currNode->right=temp;
            
            if(currNode->left)
                q.push(currNode->left);
            if(currNode->right)
                q.push(currNode->right);
        }
        return root;
        TreeNode *left=invertTree(root->left);
        TreeNode *right=invertTree(root->right);
        
        root->left=right;
        root->right=left;
        return root;   
    }
};
