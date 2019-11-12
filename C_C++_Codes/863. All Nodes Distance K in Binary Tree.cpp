/*We can consider this tree as a graph directed downwards. The problem is, we
can not go up from a node. So, we need to have a mapping to check parent of every 
node. Hashmap is going to be a good DS for this mapping as it will provide as
constant time access.
So, traverse through the tree, create a node - parent mapping and than apply BFS*/
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
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
    {
        //test cases
        if(!root)
            return vector<int>{};
        
        if(K==0)
            return vector<int>{target->val};
        
        vector<int> result;
                
        //create node to parent mapping ans save it in the hash map
        //map for node-parent mapping
        unordered_map<TreeNode*,TreeNode*> nodeToParentMap;
        createNodeParentMapping(root,NULL,nodeToParentMap);
        
        //BFS
        queue<TreeNode*>q;
        q.push(target);
        int level=0;
        set<TreeNode*> visited;
        visited.insert(target);
        
        while(!q.empty())
        {
            //if this level is the target level, get all the elements from the queue
            if(level==K)
                    return extractFromQueue(q,result);
            
            int size=q.size();
            while(size>0)
            {   
                TreeNode* node=q.front();
                q.pop();
                size--;
                
                //check the left subtree
                if(node->left!=NULL && visited.find(node->left)==visited.end())
                {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                
                //check the right subtree
                if(node->right!=NULL && visited.find(node->right)==visited.end())
                {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                
                //check the parent node
                TreeNode* parentOfCurrentNode = nodeToParentMap[node];
                if(nodeToParentMap[node]!=NULL && visited.find(parentOfCurrentNode)==visited.end())
                {
                    q.push(nodeToParentMap[node]);
                    visited.insert(parentOfCurrentNode);
                }
            }
            level++; 
        }
        return result;
    }

    //helper function: this function will create node to parent mapping
    void createNodeParentMapping(TreeNode* node, TreeNode* parent,unordered_map<TreeNode*,TreeNode*>& nodeToParentMap)
    {
        //base case
        if(node==NULL)
            return;
        
        nodeToParentMap.insert({node,parent,});
        
        createNodeParentMapping(node->left,node,nodeToParentMap);
        createNodeParentMapping(node->right,node,nodeToParentMap);
        
    }
    vector<int> extractFromQueue(queue<TreeNode*> q, vector<int>& result)
    {
        while(!q.empty())
        {
            TreeNode* node=q.front();
            result.push_back(node->val);
            q.pop();
        }
        return result;
    }
};
