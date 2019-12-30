/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*Recursively build tree.

    1) find midpoint by fast/slow method, use middle node as root.
    2) build left child by first half of the list
    3) build right child by second half of the list (head is midpoint->next)
    Read about time and space complexities from leetcode sol.
*/

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head==NULL)
            return NULL;
        if(!head->next) 
            return new TreeNode(head->val);
        
        ListNode* slow=head; ListNode* fast=head;
        ListNode* prev=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //break the list into 2 halves
        prev->next=NULL;
        
        TreeNode* root=new TreeNode(slow->val);
        
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);
        
        return root;
        
    }
};
