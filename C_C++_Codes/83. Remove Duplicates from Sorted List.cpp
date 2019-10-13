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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        
        /* Pointer to traverse the linked list */
        auto current = head;  

        /* Pointer to store the next pointer of a node to be deleted*/
        auto next_next=head;  

        /* do nothing if the list is empty */
        if (current == NULL)  
        return NULL;  

        /* Traverse the list till last node */
        while (current->next != NULL)  
        {  
            /* Compare current node with next node */
            if (current->val == current->next->val)  
            {  
                /* The sequence of steps is important*/        
                next_next = current->next->next;  
                //free(current->next);  
                current->next = next_next;  
            }  
            else /* This is tricky: only advance if no deletion */
            {  
                current = current->next;  
            }  
         }
        return head;
        
    }
};
