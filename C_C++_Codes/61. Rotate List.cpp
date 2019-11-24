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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        //base case
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        
        //close the LL into a ring
        ListNode* oldTail=head;
        int n;
        for(n=1;oldTail->next!=NULL;n++)
        {
            oldTail=oldTail->next;
        }
        oldTail->next=head;
        
        //find new tail=> (n- k % n-1)th node
        //new head: (n - k % n)th node
        ListNode* newTail=head;
        for(int i=0;i<n-k%n-1;++i)
        {
            newTail=newTail->next;
        }
        ListNode* newHead=newTail->next;
        
        //break the ring
        newTail->next=NULL;
        
        return newHead;
        
    }
};
