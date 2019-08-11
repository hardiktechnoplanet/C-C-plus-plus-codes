/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/*Soulution using priority queue
  Run time: O(n*mlog(n*m)) where n is max # of lists and m is max # of nodes in a list*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // put every element in priority queue and make a new list
        // by taking elements out from thq queue
        priority_queue<int> minHeap;
        
        // traverse through all the lists and push the elements to queue
        for(auto head:lists)
        {
            while(head!=NULL)
            {
                minHeap.push(head->val);
                head=head->next;
            }
        }
        // now, all the elemnts are in minHeap in sorted order. Make
        // a new list
        auto dummy=new ListNode(-1);
        auto head=dummy;
        
        while(!minHeap.empty())
        {
            head->next=new ListNode(minHeap.top());
            minHeap.pop();
            head=head->next;
        }
        
        // Reverse the list
        //auto curr=dummy->next;
        struct ListNode *curr, *prev;
        curr=dummy->next;
        prev=NULL;
            //auto prev=NULL;
        while(curr!=NULL)
        {
            auto next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        dummy->next=prev;
        
        return dummy->next;
        
    }
};

/*Solution 2: Using dynamic programming*/
//Time Complexity of below algorithm is O(nk logk) as outer while loop in function mergeKLists() runs log k times and every time we are processing nk elements.////
// C++ program to merge k sorted arrays of size n each 
#include <bits/stdc++.h> 
using namespace std; 

// A Linked List node 
struct Node 
{ 
	int data; 
	Node* next; 
}; 

/* Function to print nodes in a given linked list */
void printList(Node* node) 
{ 
	while (node != NULL) 
	{ 
		printf("%d ", node->data); 
		node = node->next; 
	} 
} 

/* Takes two lists sorted in increasing order, and merge 
their nodes together to make one big sorted list. Below 
function takes O(Log n) extra space for recursive calls, 
but it can be easily modified to work with same time and 
O(1) extra space */
Node* SortedMerge(Node* a, Node* b) 
{ 
	Node* result = NULL; 

	/* Base cases */
	if (a == NULL) 
		return (b); 
	else if(b == NULL) 
		return (a); 

	/* Pick either a or b, and recur */
	if(a->data <= b->data) 
	{ 
		result = a; 
		result->next = SortedMerge(a->next, b); 
	} 
	else
	{ 
		result = b; 
		result->next = SortedMerge(a, b->next); 
	} 

	return result; 
} 

// The main function that takes an array of lists 
// arr[0..last] and generates the sorted output 
Node* mergeKLists(Node* arr[], int last) 
{ 
	// repeat until only one list is left 
	while (last != 0) 
	{ 
		int i = 0, j = last; 

		// (i, j) forms a pair 
		while (i < j) 
		{ 
			// merge List i with List j and store 
			// merged list in List i 
			arr[i] = SortedMerge(arr[i], arr[j]); 

			// consider next pair 
			i++, j--; 

			// If all pairs are merged, update last 
			if (i >= j) 
				last = j; 
		} 
	} 

	return arr[0]; 
} 

// Utility function to create a new node. 
Node *newNode(int data) 
{ 
	struct Node *temp = new Node; 
	temp->data = data; 
	temp->next = NULL; 
	return temp; 
} 

// Driver program to test above functions 
int main() 
{ 
	int k = 3; // Number of linked lists 
	int n = 4; // Number of elements in each list 

	// an array of pointers storing the head nodes 
	// of the linked lists 
	Node* arr[k]; 

	arr[0] = newNode(1); 
	arr[0]->next = newNode(3); 
	arr[0]->next->next = newNode(5); 
	arr[0]->next->next->next = newNode(7); 

	arr[1] = newNode(2); 
	arr[1]->next = newNode(4); 
	arr[1]->next->next = newNode(6); 
	arr[1]->next->next->next = newNode(8); 

	arr[2] = newNode(0); 
	arr[2]->next = newNode(9); 
	arr[2]->next->next = newNode(10); 
	arr[2]->next->next->next = newNode(11); 

	// Merge all lists 
	Node* head = mergeKLists(arr, k - 1); 

	printList(head); 

	return 0; 
} 

