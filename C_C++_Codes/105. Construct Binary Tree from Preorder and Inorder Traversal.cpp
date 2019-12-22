/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* https://www.youtube.com/watch?v=PoBGyrIWisE
   Check the leet code solution also.
   
   Preorder: root left right
   Inorder:  left root right
   
   Copy the inorder vector values along with the index in an unordered_map
   to decrease the time complexity for search.
   Now, take the current value from preorder vector as root, find its index
   in the unordered_map. All the values to the left of this index in inorder
   vector will be in the left subtree and all the values to the right will
   be in the right subtree. Repeat this process.
   
   Time and Space complexity: O(n)*/
class Solution {
public:
    unordered_map<int,int>mem;
    int preorderIndex=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        //test case
        if(preorder.size()==NULL || inorder.size()==NULL)
            return NULL;
        
        //copy the inorder values and the corresponding index in the map
        for(size_t i=0;i<inorder.size();++i)
        {
            mem[inorder[i]]=i;
        }
        return helper(0,inorder.size(),preorder,inorder);
    }
    
    TreeNode* helper(int leftIndex,int rightIndex,vector<int>& preorder,vector<int>& inorder)
    {
        //base case
        //no element to construct the subtrees
        if(leftIndex==rightIndex)
            return NULL;
        
        //pick up the preorderIndex element as root
        int rootVal=preorder[preorderIndex];
        TreeNode* root=new TreeNode(rootVal);
        preorderIndex++;
        
        //split the inorder vector into left and right subtrees
        //find the index of the root in inroder vector
        int rootIndex=mem[rootVal];
        
        //recursion
        //the left subtree will have the values from leftIndex
        //to rootIndex in inorder vector
        root->left=helper(leftIndex,rootIndex,preorder,inorder);
        
        //the right subtree will have the values from rootIndex+1
        //to rightIndex in inorder vector
        root->right=helper(rootIndex+1,rightIndex,preorder,inorder);
        
        return root;
        
    }
};
