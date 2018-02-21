#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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
void nthElement(int n)
{
	struct Node* p1=head;
	struct Node* p2=head;
	for(int i=0;i<n-1;i++)
	{
		p2=p2->next;
	}
	while(p2->next!=NULL)
	{
		p1=p1->next;
		p2=p2->next;
	}
	cout<<p1->data<<endl;
	//cout<<"hello";
}
int main(int argc, char** argv) {
	head=NULL;
	printf("how many numbers?\n");
	int n,i,x,q;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("enter the numbers\n");
		scanf("%d",&x);
		Insert(x);
		//Print();
	}
	Print();
	printf("enter the element position with respect to the last element which we want to find\n");
	scanf("%d",&q);
	nthElement(q);
   	return 0;
}
