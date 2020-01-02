//Solution 1: Recursive
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        int maxD=0;
        if(root==NULL)
        {
            return maxD;
        }
        return dfsHelper(root);
    }
    int dfsHelper(TreeNode* node)
    {
        if(node==NULL)
        {
            return 0;
        }
        else
        {
            int leftDepth=dfsHelper(node->left);
            int rightDepth=dfsHelper(node->right);
            
            return max(leftDepth,rightDepth)+1;
        }
        
    }
};

/*
//Solution 2: Iterative: BFS
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        int maxD=0;
        if(root==NULL)
        {
            return maxD;
        }
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            maxD++;
            int size=q.size();
            for(size_t i=0;i<size;++i)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return maxD;
    }
};*/
