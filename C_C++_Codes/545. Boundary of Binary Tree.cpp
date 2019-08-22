/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/*Using Recursion
We will travers the left tree and save the nodes val in top-down manner, save the leaf
nodes and then traverse the right side tree from down to top*/
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> result;
        
        if(root==NULL)
            return result;
        
        result.push_back(root->val);
        
        // Print the left boundary in top-down manner. 
        leftHelper(root->left,result);
        
        // Print all leaf nodes 
        leavesHelper(root->left,result);
        leavesHelper(root->right,result);
        
        // Print the right boundary in bottom-up manner 
        rightHelper(root->right,result);
        
        return result;
    }
    
    // A function to print all left boundary nodes, except a leaf node. 
    // Print the nodes in TOP DOWN manner
    void leftHelper(TreeNode* root,vector<int>& result)
    {
        //base case
        if(root==NULL)
        {
            return;
        }
        
        // to ensure top down order, print the node 
        // before calling itself for left subtree 
        if(root->left)
        {
            result.push_back(root->val);
            leftHelper(root->left,result);
        }
        else if(root->right)
        {
            result.push_back(root->val);
            leftHelper(root->right,result);
        }
        // do nothing if it is a leaf node, this way we avoid 
        // duplicates in output
    }
    
    // A function to print all right boundary nodes, except a leaf node 
    // Print the nodes in BOTTOM UP manner 
    void rightHelper(TreeNode* root,vector<int>& result)
    {
        //base case
        if(root==NULL)
        {
            return;
        }
        
        // to ensure bottom up order, first call for right 
        // subtree, then print this node
        if(root->right)
        {
            rightHelper(root->right,result);
            result.push_back(root->val);
        }
        else if(root->left)
        {
            rightHelper(root->left,result);
            result.push_back(root->val);
        }
        // do nothing if it is a leaf node, this way we avoid 
        // duplicates in output 
    }
    
    void leavesHelper(TreeNode* root,vector<int>& result)
    {
        //base case
        if(root==NULL)
        {
            return;
        }
        leavesHelper(root->left,result);
        
        // Push in result it if it is a leaf node
        if(!root->left && !root->right)
        {
            result.push_back(root->val);
        }
        
        leavesHelper(root->right,result);
    }
};

/*Iterative solution*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        
        vector<int> result;
        
        //check if root is not null
        if (root) 
        { 
            result.push_back(root->val);
            // If there is only 1 node print it 
            // and return 
            if (!(root->left) && !(root->right)) { 
                return result; 
            }  

            // Traverse left boundary without root 
            // and last node 
            TreeNode* L = new TreeNode(0);
            if(root->left)
            {
                L=root->left; 
                while (L) 
                {
                    result.push_back(L->val); 
                    if(L->left)
                    {
                        L=L->left;
                    }
                    else
                    {
                        //if the nodes does not have a left node, but, it
                        //has a right node, in this case this right node
                        //in left tree will be our boundary node
                        if(L->right)
                        {
                            L=L->right;
                        }
                        else
                        {
                            break;
                        }
                    } 
                } 
            }
            //remove the last element because it will be added again
            //by printLeaves function
            
            if(!result.empty() && result.size()>1)
            result.erase(--result.end());

            // BFS designed to only include leaf nodes 
            printLeaves(root,result);

            // Traverse right boundary without root 
            // and last node 
            vector<int> result_r; 

            TreeNode* R = new TreeNode(0);
            if(root->right)
            {
                R=root->right; 
               while (R) 
               {
                   
                   result_r.push_back(R->val);
                    if(R->right)
                    {
                        R=R->right;
                    }
                    else
                    {
                        if(R->left)
                        {
                            R=R->left;;
                        }
                        else
                        {
                            break;
                        }
                    }
                } 
            }
            //remove the last element(duplicate value)
            if(!result_r.empty())
            result_r.erase(--result_r.end());


            // Reversing the order for the right tree result 
            reverse(result_r.begin(), result_r.end()); 

            // Concatenating the two lists 
            result.insert(result.end(), result_r.begin(), 
                                     result_r.end()); 

    }
        return result;
    }
    void printLeaves(TreeNode* root,vector<int>& result) 
    {
        if (root == NULL) 
        return;
        
        printLeaves(root->left,result); 
  
        // Print it if it is a leaf node 
        if (!(root->left) && !(root->right)) 
            //printf("%d ", root->data);
            result.push_back(root->val);

        printLeaves(root->right,result); 

    }
};*/
