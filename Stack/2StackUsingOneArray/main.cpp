#include <iostream>
# define n 20
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int array[n];
int top1=-1;
int top2=n;
void push1(int x)
{
	if(top1<top2-1)
	{
		top1++;
		array[top1]=x;
	}
	else{
	cout<<"stack overflow";
	exit(1);}
	//cout<<"top1:"<<top1<<endl;
	//cout<<"top2:"<<top2<<endl;
}
void push2(int x)
{
	if(top1<top2-1)
	{
		top2--;
		array[top2]=x;
	}
	else{
	cout<<"stack overflow";
	exit(1);}
}
int pop1()
{
	if(top1>=0)
	{
		int x=array[top1];
		top1--;
		return x;
	}
	else{
	cout<<"stack underflow";
	exit(1);}
}
int pop2()
{
	if(top2<n)
	{
		int x=array[top2];
		top2--;
		return x;
	}
	else{
	cout<<"stack underflow";
	exit(1);}
}
void print()
{
	cout<<"Stack1:";
	for(int i=0;i<=top1;i++)
	{
		cout<<"\t"<<array[i];
	}
}
int main(int argc, char** argv) {
	push1(1);
	push1(2);
	push1(3);
	push1(4);
	print();
	push2(10);
	push2(20);
	push2(30);
	push2(40);
	//pop1();
	cout<<"the popped element from stack one:"<<pop1()<<endl;
	cout<<"the popped element from stack one:"<<pop2()<<endl;
	//pop1();
	//cout<<"the popped element from stack one:"<<pop1()<<endl;
	return 0;
}
