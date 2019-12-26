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
    bool isPalindrome(ListNode* head) 
    {
        //test case
        if(head==NULL)
            return true;
        
        //find the end of first half and start node of the second half
        ListNode *firstHalfEnd=findFirstHalfEnd(head);
        ListNode *secondHalfStart=reverseList(firstHalfEnd->next);
        
        //check if palindrome
        ListNode *p1=head;
        ListNode *p2=secondHalfStart;
        bool result=true;
        while(p2!=NULL && result)
        {
            if(p1->val!=p2->val)
                result= false;
            p1=p1->next;
            p2=p2->next;
        }
        //restore the list and return result
        firstHalfEnd->next=reverseList(secondHalfStart);
        return result;
    }
      
    ListNode* findFirstHalfEnd(ListNode * head)
    {
        //get the second half of the linked list
        ListNode *slowPtr=head;
        ListNode *fastPtr=head;
        while(fastPtr->next!=NULL && fastPtr->next->next!=NULL)
        {
            slowPtr=slowPtr->next;
            fastPtr=fastPtr->next->next;
        }
        
        return slowPtr; 
    }
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode *prev=NULL; 
        ListNode *curr=head;
        while(curr!=NULL)
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};
