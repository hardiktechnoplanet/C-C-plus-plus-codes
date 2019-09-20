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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto ptr1=head;
	auto ptr2=head;
	
	//move ptr1 to the nth node
	for(size_t i=0;i<n;++i)
    {
        ptr1=ptr1->next;
    }
    
    if(!ptr1) return head->next;
	
	/*Move them at the same pace. When p1-next hits the end (
    we dont have to take p1 to Null because p2 should point at the n-1 the element)
    , p2 will be at the n-1 element*/
	while(ptr1->next!=NULL)
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}

    //adjust the pointer
	ptr2->next=ptr2->next->next;
    return head;
        
    }
};
