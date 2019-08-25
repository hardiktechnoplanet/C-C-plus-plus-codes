/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

/*We will use 2 passes. In the first pass, clone the linked list (Give all nodes their clone in the mapping.)
and in the second pass adjust the next and random pointer(Reset the curr pointer to the head of the original list
Give all clones their next and random pointer assignments.)

Time Complexity and Space Compexity both are O(n)*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        //test case
        //If the head is null then no cloning can happen
    
        if (head == NULL) 
        {
          return NULL;
        }
        
        // Initialize two references, 
        // one with original list's head. 
        Node *origCurr = head; 
        Node *cloneCurr = NULL; 
  
        // Hash map which contains node  
        // to node mapping of original  
        // and clone linked list. 
        unordered_map<Node*, Node*> cloneMap; 
        
        //First Pass
        // Traverse the original list and 
        // make a copy of that in the  
        // clone linked list. 
        while (origCurr != NULL) 
        { 
            cloneCurr = new Node(origCurr->val); 
            cloneMap[origCurr] = cloneCurr; 
            origCurr = origCurr->next; 
        } 
  
        // Adjusting the original list  
        // reference again. 
        origCurr = head; 
  
        // Traversal of original list again 
        // to adjust the next and random  
        // references of clone list using  
        // hash map. 
        while (origCurr != NULL) 
        { 
            cloneCurr = cloneMap[origCurr]; 
            cloneCurr->next = cloneMap[origCurr->next]; 
            cloneCurr->random = cloneMap[origCurr->random]; 
            origCurr = origCurr->next; 
        } 
  
        // return the head reference of  
        // the clone list. 
        return (cloneMap[head]); 

  }
        
        
    
};
