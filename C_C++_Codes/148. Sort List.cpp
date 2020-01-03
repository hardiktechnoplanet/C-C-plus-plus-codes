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
    ListNode* sortList(ListNode* head) 
    {
        //test case
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        
        ListNode* lft_list=sortList(head);
        ListNode* rgt_list=sortList(slow);
        
        return mergeLists(lft_list,rgt_list);
    }
    
    ListNode* mergeLists(ListNode* l1, ListNode* l2)
    { 
        auto dummy=new ListNode(INT_MIN);
        auto curr=dummy;
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                curr->next=l1;
                l1=l1->next;
            }
            else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        curr->next=l1?l1:l2;
        return dummy->next;
    }
};
