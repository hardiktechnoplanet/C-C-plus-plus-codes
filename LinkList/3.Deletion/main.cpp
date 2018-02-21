#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node{
	int data;
	struct Node* next;
};
struct Node* head;
void Insert(int x)
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
void deleteNodeWithPosition(int n)
{
	struct Node* temp1=head;
	for(int i=0;i<n-2;i++)
	{
		temp1=temp1->next;
	}
	struct Node* temp2=temp1->next;
	temp1->next=temp2->next;
	free(temp2);	
}
void deleteWithNumber(int n)
{
	struct Node* temp=head;
	cout<<head->data<<endl;
	//struct Node* previous=(Node*)malloc(sizeof(struct Node));
	struct Node* previous=head;
	while(temp->data!=n)
	{
		previous=temp;
		temp=temp->next;
	}
	if(previous==temp)
	{
		head=temp->next;
	}
	else
	previous->next=temp->next;
	free(temp);
}
/*bool duplicate(int n)
{
struct Node* temp=head;
int array[256]={0};
	for(int i=0;i<n;i++)
	{
		if(array[temp->data]==0)
		{
		array[temp->data]=1;
		temp=temp->next;
	}
		else
		return false;
		}
		return true;	
}*/
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
int main(int argc, char** argv) {
	head=NULL;
	printf("how many numbers?\n");
	int n,i,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("enter the numbers\n");
		scanf("%d",&x);
		Insert(x);
		//Print();
	}
	Print();
	printf("enter the position to be deleted\n");
	int q;
	scanf("%d",&q);
	//deleteNodeWithPosition(q);
	printf("enter the number to be deleted\n");
	int w;
	scanf("%d",&w);
	deleteWithNumber(w);
	Print();
   	return 0;
}
