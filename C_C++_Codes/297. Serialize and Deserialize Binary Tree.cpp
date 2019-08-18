/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
       string result="";
       serializeHelper(root,result);
       return result;
    }
    void serializeHelper(TreeNode* node, string& res)
    {
        //base case: when the node is null
        if(node==NULL)
        {
            res.append("null");
            res.append(",");
        }
        else
        {
            res.append(to_string(node->val));
            res.append(",");
            //cout<<res<<"\t";
            //recursion
            serializeHelper(node->left,res);
            serializeHelper(node->right,res);
        }
    }
    
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        vector<string> tr;
        istringstream str(data);
        string word;
        
        while(getline(str,word,',')){
            tr.push_back(word);
        }
        
        int index=0;
        return deserializeHelper(tr,index);
    }
    TreeNode* deserializeHelper(vector<string>& tr,int& index)
    {        
        string temp;
        if(index<tr.size())
        {
            temp=tr[index++];
        }
        
        //base case
        if(temp=="null" || index>=tr.size())
        {
            return NULL;
        }

        auto root=new TreeNode(stoi(temp));
        root->left=deserializeHelper(tr,index);
        root->right=deserializeHelper(tr,index);
        
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
