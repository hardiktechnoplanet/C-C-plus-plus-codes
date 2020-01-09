/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* https://www.youtube.com/watch?v=s5XRtcud35E
Inorder: Left Root Right, root is in between left and right so we can not find root from Inorder
traversal. Postorder: Left Right Root, root is at the end, so we can traverse the array from the end
to get the root.*/

unordered_map <int,int> inorderMap;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        //test case
        if(postorder.empty() || inorder.empty())
            return NULL;
        
        //copy the inorder vector in the map to decrease the search time
        for(size_t i=0;i<inorder.size();++i)
        {
            inorderMap[inorder[i]]=i;
        }
        int postOrderIndex=postorder.size()-1;
        
        return helper(0,inorder.size()-1, postOrderIndex,postorder);
        
    }
    TreeNode* helper(int leftIndex, int rightIndex, int& postOrderIndex,vector<int>& postorder)
    {
        //base case
        if(leftIndex>rightIndex)
            return NULL;
        
         //pick up the postorderIndex element as root
        int rootVal=postorder[postOrderIndex];
        TreeNode* root=new TreeNode(rootVal);
        postOrderIndex--;
        
        //split the inorder vector into left and right subtrees
        //find the index of the root in inroder vector
        int rootIndex=inorderMap[rootVal];
        
        //recursion
        //post order is left right root, we have started from root, so first build the right sub tree
        root->right=helper(rootIndex+1,rightIndex,postOrderIndex,postorder);
        root->left=helper(leftIndex,rootIndex-1,postOrderIndex,postorder);
        
        return root;
        
    }
};
