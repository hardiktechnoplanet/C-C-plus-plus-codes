#include<bits/stdc++.h>
#include <iostream>
using namespace std;


  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummyHead = new ListNode(0);
    auto p = l1, q = l2, curr = dummyHead;
    int carry = 0;
    while (p != NULL || q != NULL) {
        int x,y=0;
        if(p!=NULL)
        {
            x=p->val;
        }
        else
            x=0;
        if(q!=NULL)
        {
            y=q->val;
        }
        else
            y=0;
        //int x = (p != null) ? p.val : 0;
        //int y = (q != null) ? q.val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
        if (p != NULL) p = p->next;
        if (q != NULL) q = q->next;
    }
    if (carry > 0) {
        curr->next = new ListNode(carry);
    }
    return dummyHead->next;
    }

