//check the leet code solution
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
    ListNode* oddEvenList(ListNode* head) 
    {
        //test case
        if(head==NULL)
            return head;
        
        ListNode *odd=head, *even=odd->next,*evenHead=even;
        while(even!=NULL && even->next!=NULL)
        {
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        //connect odd and even list
        odd->next=evenHead;
        
        return head;
        
    }
};
