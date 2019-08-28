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
    int countNodes(TreeNode* root) {
        
        int count=0;
        //test case
        if(root==NULL)
            return count;
        
        queue<TreeNode*>q;
        //push the root in the queue and increment the count
        q.push(root);
        count++;
        
        while(!q.empty())
        {
            int size=q.size();
            for(size_t i=0;i<size;++i)
            {
                TreeNode* node=q.front();
                q.pop();
                //add the left child
                if(node->left)
                {
                    q.push(node->left);
                    count++;
                }
                //add the right child
                if(node->right)
                {
                    q.push(node->right);
                    count++;
                }
            }
        }
        return count;
    }
};

/*Recursive solution*/
/*class Solution {
public:
    int countNodes(TreeNode* root) 
	{
		//base case
        if(root==NULL)
        {
            return 0;
        }
        count++;
        countNodes(root->left);
        countNodes(root->right);
        return count;
    }
};*/
