/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

/*https://www.youtube.com/watch?v=5cPbNCrdotA
There are 2 cases: 1) if there is a right subtree for the node: the successor or
next biggest value will be the leftmost child in this right sub tree.
2) If there is no right sub tree: the deepest parent (or parent in this question)
will be the next biggest value or successor. There will be 2 subcases for this case.
Subcase 1: if the node is right child of its parent, we need to go up to the parent
(first parent) for which this node is in its left subtree.
Subcase 2: if the node is the left child or its parent, return the parent.

Time Complexity: O(h): where h is the tree height. That means O(log N) in the 
average case, and O(N) in the worst case, where N is the number of nodes in the tree.

Space complexity :O(1), since no additional space is allocated during the calculation.
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) 
    {
        //test case
        if(node==NULL)
            return NULL;
        
        //Case 1: if there is a right sub tree:
        //to to the leftmost element in the right sub tree
        if(node->right)
        {
            Node *currNode=node->right;
            while(currNode->left)
                currNode=currNode->left;
            
            return currNode;
        }
        
        //Case 2: no right sub tree
        //find the deepest parent of the node
        else
        {
            while (node->parent)
            {
                //there are 2 sub cases
                //Case a: if the node is right child of its parent, we need to up
                //to find a parent node for which node is left subchild
                if (node == node->parent->right)
                    node = node->parent;
                
                //Case b: if the node is left child of parent, return parent node
                else
                    return node->parent;
            }
        }
        return NULL;
        
    }
};
