#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Iterative Solution
// Take a queue, push the first discovered element, visit that element and enqueue its childrens
//Time Complexity: O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //return the result vector
        vector<vector<int> > result;
        
        //test case
        if(root==NULL)
            return result;
        
        queue<TreeNode*> q;
        //push the root node in the queue
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> currentLevel;
            int size=q.size();
            
            //for loop will go till the size of the queue
            for(size_t i=0; i<size;++i)
            {
                TreeNode* node=q.front();
                q.pop();
                currentLevel.push_back(node->val);
                if(node->left !=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
            }
            result.push_back(currentLevel);
        }
        return result;
    }
};

//Recursive Solution
//Pass the tree level to the function
vector<vector<int>> result;
vector<vector<int>> levelOrder(TreeNode* root) 
{
	return levelOrderHelper(root,0);
}

vector<vector<int> > levelOrderHelper(TreeNode* node, int level)
{
	//base case
	if(node==NULL)
	{
		return;
	}
	//declare an empty vector
	vector<int> epty;
	//if the vector size and level is same, it means we have to push an empty vector
	//at this index and than push the elements. If the size and level is not same,
	//we are processing the same level, so, directly push the next element.
	if(result.size()==level)
	{
		result.push_back(epty);
	}
	result[level].push_back(node->val);
	
	//recursion calls
	levelOrderHelper(node->left,level+1);
	levelOrderHelper(node->right,level+1);
}
int main(int argc, char** argv) {
	return 0;
}
