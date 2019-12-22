/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* https://www.youtube.com/watch?v=xRYPjDMSUFw 
1) Divide the list into 2 parts. 
2) Reverse the second half. 
3) Now, take one element from each list one by one*/

class Solution {
public:
    void reorderList(ListNode* head) 
    {
        //test case
        if(head==NULL || head->next==NULL)
            return;
        
        //head of first list
        ListNode* l1=head;
        //tail of first list
        ListNode* prev=NULL;
        //head of second list
        ListNode* slow=head;
        //tail of second list
        ListNode* fast=head;
        
        //divide the list into two parts
        while(fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        
        //reverse the second list
        ListNode* l2= reverseList(slow);
        
        //merge the two lists by taking one element from first list in one cycle
        //and from other in the next cycle
        mergeLists(l1,l2);
    }
    
    //reverse a linked list
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev= NULL;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void mergeLists(ListNode* l1, ListNode* l2)
    {
        while(l1!=NULL)
        {
            ListNode* l1_next=l1->next;
            ListNode* l2_next=l2->next;
            
            l1->next=l2;
            if(l1_next==NULL)
                break;
            
            l2->next=l1_next;
            
            l1=l1_next;
            l2=l2_next;
        }
    }
};
