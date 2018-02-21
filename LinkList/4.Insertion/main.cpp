#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//structure of a node
struct Node
{
	int data;
	struct Node* next;
};
struct Node* head;
void Insert(int x)
{
	Node* temp=(Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=NULL;
	if(head!=NULL)
	{
		temp->next=head;
	}
		head=temp;
}
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
int main(int argc, char** argv) 
{
	head=NULL; 
	int x;
	printf("how many numbers?\n");
	int n,i;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("enter the number\n");
		scanf("%d",&x);
		Insert(x);
		Print();
	}
	return 0;
}
