#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Time complexity: O(n), space complexity: O(1)
void reverseKthNode(struct node *curr,int k)
{
	//test case: if there is no element, one element or K is 0 or -ve
	if(curr==NULL || curr->next==NULL || k<=0)
	{
		return;
	}
	
	auto front=new ListNode(0);
	auto back, start=new ListNode(0), end=new ListNode(0);
	int count;
	int subListCount=0;
	
	while(curr!=NULL)
	{
		count=0;
		back=NULL;
		start=curr;
		
		while(curr!=NULL && count<k)
		{
			front=curr->next;
			curr->next=back;
			back=curr;
			curr=front;
			
			count++;
		}
		subListCount++;
		if(subListCount==1)
		{
			head=back;
		}
		else
		{
			end->next=back;
		}
		end=start;
	}
}

/*Recursive solution*/
/*
struct ListNode *reverseKthNode(struct node *curr,int k)
{
	//test case: if there is no element, one element or K is 0 or -ve
	if(curr==NULL)
	{
		return NULL;
	}
	
	if(k<=0)
	{
		return curr;
	}
	
	auto front=new ListNode(0);
	auto back=new ListNode(0);
	int count;
	auto end=curr;
	
	
	while(curr!=NULL && count<k)
	{
		front=curr->next;
		curr->next=back;
		back=curr;
		curr=front;
		
		count++;
	}
	end->next=reverseKthNode(curr,k);
	return back;
}
*/


int main(int argc, char** argv) {
	return 0;
}
