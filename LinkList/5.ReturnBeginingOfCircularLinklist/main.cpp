#include <iostream>
struct Node{
	int data;
	struct Node* next;
};
function()
{
	struct Node* n1=head;
	struct Node* n2=head;
	while(n2->next!=NULL)
	{
		n1=n1->next;
		n2=n2->next->next;
		if(n1==n2)
		break;
	}
	if(n2->next==NULL)
	return NULL;
	
	n1=head;
	while(n1!=n2)
	{
		n1=n1->next;
		n2=n2->next;
	}
	return n2;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	return 0;
}
