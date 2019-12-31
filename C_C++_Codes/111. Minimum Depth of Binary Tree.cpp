/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*Approach 1: Recursion

Complexity analysis
Time complexity : we visit each node exactly once, thus the time complexity is O(N), where N
is the number of nodes.
Space complexity : in the worst case, the tree is completely unbalanced, e.g. each node has only one child node, the recursion call would occur N times (the height of the tree), therefore the storage to keep the call stack would be O(N). But in the best case (the tree is completely balanced), the height of the tree would be log(N). Therefore, the space complexity in this case would be O(log(N)).*/

/*class Solution {
public:
    int minDepth(TreeNode* root) 
    {
        //base case
        if(root==NULL)
            return 0;
        
        //leaf node
        if(root->left==NULL && root->right==NULL)
            return 1;
        
        int min_Depth=INT_MAX;
        
        if(root->left)
            min_Depth=min(minDepth(root->left),min_Depth);
        
        if(root->right)
            min_Depth=min(minDepth(root->right),min_Depth);
        
        return min_Depth+1;
        
    }
};*/

/*Approach 2: DFS Iteration
Start from a stack which contains the root node and the corresponding 
depth which is 1. Then proceed to the iterations: pop the current node out 
of the stack and push the child nodes with incrementing the current depth. 
The minimum depth is updated at each leaf node.

Complexity analysis
Time complexity : each node is visited exactly once and time complexity is O(N).
Space complexity : in the worst case we could keep up to the entire tree, that results in O(N) space complexity.
*/

/*class Solution {
public:
    int minDepth(TreeNode* root) 
    {
        //test case
        if(root==NULL)
            return 0;
        
        //take a stack, store the node and current depth
        stack<pair<TreeNode*,int>> st;
        st.push({root,1});
        
        int min_depth=INT_MAX;
        
        while(!st.empty())
        {
            auto curr=st.top();
            st.pop();
            
            TreeNode* node=curr.first;
            int current_depth=curr.second;
            
            //check if this node is a leaf node, if yes, update
            //the min_depth
            if(node->left==NULL && node->right==NULL)
                min_depth=min(min_depth,current_depth);
            
            if(node->left)
                st.push({node->left,current_depth+1});
            
            if(node->right)
                st.push({node->right,current_depth+1});
        }
        return min_depth;
    }
};*/


/*Solution 3: BFS Iteration
The drawback of the DFS approach in this case is that all nodes should be visited to ensure that the minimum depth would be found. Therefore, this results in a O(N) complexity. One way to optimize the complexity is to use the BFS strategy. We iterate the tree level by level, and the first leaf we reach corresponds to the minimum depth. As a result, we do not need to iterate all nodes.

Complexity analysis
Time complexity : in the worst case for a balanced tree we need to visit all nodes level by level up to the tree height, that excludes the bottom level only. This way we visit N/2 nodes, and thus the time complexity is O(N).

Space complexity : is the same as time complexity here O(N).
*/
class Solution {
public:
    int minDepth(TreeNode* root) 
    {
        //test case
        if(root==NULL)
            return 0;
        
        //take a stack, store the node and current depth
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        
        int current_depth=0;
        
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();
            
            TreeNode* node=curr.first;
            current_depth=curr.second;
            
            //check if this node is a leaf node, if yes, we have found
            //the min_depth
            if(node->left==NULL && node->right==NULL)
                break;
            
            if(node->left)
                q.push({node->left,current_depth+1});
            
            if(node->right)
                q.push({node->right,current_depth+1});
        }
        return current_depth;
    }
};
