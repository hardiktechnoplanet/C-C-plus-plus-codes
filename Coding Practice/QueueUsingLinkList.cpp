#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};
struct Node* head;

void Print()
{
	struct Node* temp=head;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void push(int x)
{
	struct Node* temp=(Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=NULL;
	//head=temp;
	if(head!=NULL)
	{
		temp->next=head;
	}
	head=temp;
}

void pop()
{
	int count=0;
	struct Node* temp1=head;
	struct Node* temp2=head;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
		//count variable will have the value equal to link list 
		//size
		count++;
	}
	cout<<"temp1: "<<temp1->data<<endl;
	cout<<"count: "<<count<<endl;
	//test case: if the link list size is 1
	if(count==0)
	{
		head=NULL;
		return;
	}
	for(int i=0;i<count-1;i++)
	{
		temp2=temp2->next;
	}
	cout<<"temp2: "<<temp2->data<<endl;
	temp2->next=temp1->next;
	
	free(temp1);
}

int main(int argc, char** argv) {
	head=NULL;
	printf("how many numbers?\n");
	int n,i,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("enter the numbers\n");
		scanf("%d",&x);
		push(x);
	}
	Print();
	pop();
	Print();
   	return 0;
}
