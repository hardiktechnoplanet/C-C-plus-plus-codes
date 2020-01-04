/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*Solution 1: Recursive Solution
Save the inorder traversal in an array. The array will be sorted.
Return the value at k-1 index in the array.
Time and Space Complexity: O(n)*/

/*class Solution {
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        if(root==NULL)
            return 0;
        vector<int> sortedTree;
        inOrderHelper(root,sortedTree);
        return sortedTree[k-1];
    }
    void inOrderHelper(TreeNode* node, vector<int>& sortedTree)
    {
        if(node==NULL)
            return;
        
        inOrderHelper(node->left,sortedTree);
        sortedTree.push_back(node->val);
        inOrderHelper(node->right,sortedTree);
    }
};*/

// Solution 2: Iterative
/*The recursion could be converted into iteration, with the help of stack. This way one could speed up the solution because there is no need to build the entire inorder traversal, and one could stop after the kth element.
Complexity Analysis
Time complexity : O(H+k), where H is a tree height. This complexity is defined by the stack, which contains at least H+k elements, since before starting to pop out one has to go down to a leaf. This results in O(logN+k) for the balanced tree and O(N+k) for completely unbalanced tree with all the nodes in the left subtree.
Space complexity : O(H+k), the same as for time complexity,O(N+k) in the worst case, and O(logN+k) in the average case.

*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        if(root==NULL)
            return 0;
        stack<TreeNode*>st;
        st.push(root);
        
        while(true)
        {
            while(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            if(--k==0)
                return root->val;
            root=root->right;
        }
    }
};
