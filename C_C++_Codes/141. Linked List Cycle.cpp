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
    bool hasCycle(ListNode *head) 
    {
        auto slwPtr=head;
        auto fstPtr=head;
        //firstly, find the meeting point
        while(fstPtr!=NULL && fstPtr->next!=NULL)
        {
            slwPtr=slwPtr->next;
            fstPtr=fstPtr->next->next;
            if(slwPtr==fstPtr)
                return true;
        }
        return false;
        
    }
};
