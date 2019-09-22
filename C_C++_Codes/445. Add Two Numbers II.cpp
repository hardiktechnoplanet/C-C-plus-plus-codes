//use 2 stacks and push the linked lists vals on these stacks.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        stack<int> s1,s2;
        
        while(l1!=NULL)
        {
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            s2.push(l2->val);
            l2=l2->next;
        }
        
        auto node=new ListNode(0);
        node->next=NULL;
        //auto curr=node;
        int carry=0;
        while(!s1.empty() || !s2.empty())
        {
            int x=0,y=0;
            if(!s1.empty())
            {
                x=s1.top();
                s1.pop();             
            }
            
            if(!s2.empty())
            {
                y=s2.top();
                s2.pop();
            }
            
            int sum=x+y+carry;
            carry=sum/10;
         
            //we need to insert the sum at the end of the linked list to be returned
            auto curr=new ListNode(sum%10);
            curr->next=node->next;
            node->next=curr; 
        }
        if(carry>0)
        {
            auto curr=new ListNode(carry);
            curr->next=node->next;
            node->next=curr;
        }
        return node->next;
    }
};
