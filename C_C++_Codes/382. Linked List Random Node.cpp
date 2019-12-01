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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    int size=0;
    ListNode* headNode=new ListNode(NULL);
    Solution(ListNode* head) 
    {
        auto p=head;
        headNode=head;
        while(p!=NULL)
        {
            size++;
            p=p->next;
        }
        
    }
    
    /** Returns a random node's value. */
    int getRandom() 
    {
        int random=rand()%size;
        auto p=headNode;
        for(size_t i=0;i<random;++i)
        {
            p=p->next;
        }
        return p->val;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
