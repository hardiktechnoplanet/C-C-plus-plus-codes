/*Solution 1: Iterative - O(n)
Start from the head node and traverse the list. While traversing 
swap data of each node with its next node�s data.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        auto node=head;
        
        //Traverse further only if  
        //there are at-least two nodes left
        while(node!=NULL && node->next!=NULL)
        {
            //Swap data of node with its next node's data
            swap(node->val,node->next->val);
            
            //Move temp by 2 for the next pair
            node=node->next->next;
        }
        return head;   
    }
};

/*Solution 2: Recursive - O(n)
If there are 2 or more than 2 nodes in Linked List then swap the first 
two nodes and recursively call for rest of the list.
*/
/*class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        auto node=head;
        
        //There must be at-least two nodes in the list 
        if (node != NULL && node->next != NULL) 
        { 

            //Swap the node's data with data of next node
            swap(node->val, node->next->val); 

            //Call swapPairs() for rest of the list
            swapPairs(node->next->next); 
        } 
        return head;
    }
};*/
