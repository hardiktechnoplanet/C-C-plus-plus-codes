/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    vector<int> vec;
    int iterator;
    BSTIterator(TreeNode* root) 
    {
        helper(root,vec);
        iterator=0;
        
    }
    void helper(TreeNode* node, vector<int>& vec)
    {
        if(node==NULL)
            return;
        
        helper(node->left,vec);
        vec.push_back(node->val);
        helper(node->right,vec);
    }
    
    /** @return the next smallest number */
    int next() 
    {
        return vec[iterator++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        if(iterator==vec.size())
            return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
