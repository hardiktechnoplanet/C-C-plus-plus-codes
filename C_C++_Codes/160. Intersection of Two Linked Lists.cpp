/*Time complexity : O(m+n).
Space complexity : O(m) 0r O(n)*/

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
    ListNode *getIntersectionNode(ListNode *list1_head, ListNode *list2_head) {
        
        unordered_set <struct ListNode*> list_1_nodes;
	
        while(list1_head!=NULL)
        {
            list_1_nodes.insert(list1_head);
            list1_head=list1_head->next;
        }

        while(list2_head!=NULL)
        {
            if(list_1_nodes.find(list2_head)!=list_1_nodes.end())
            {
                return list2_head;
            }
            list2_head=list2_head->next;
        }
        return NULL;

    }
};
