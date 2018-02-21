#include <iostream>
# define size 20
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int array[size];
int min_array[size];
int q=-1;
//min[0]=array[0];
int top=-1;

//int min=0;
int minimum()
{
	cout<<"value of q: "<<q<<endl;
	cout<<"minimum value is: "<<min_array[q]<<endl;
	//return min;
}
void push(int x)
{
	//int min[size];
	//int q=-1;
	if(top<size)
	{
		if(top==-1)
		{
			//top++;
			q++;
			min_array[q]=x;
		}
		else
		{
			int min_val =array[top];
			if(x<min_val)
			{
				//top++;
				q++;
				min_array[q]=x;
			}
		}
			/*if(array[top]<x)
			{
				top++;
			min[top]=array[top];
		}
			else if(array[top]>x)
			{
			top++;
			min[top]=x;
		}}*/
		top++;
		array[top]=x;
		
	}
	else{
	cout<<"stack overflow";
	exit(1);}
	//cout<<"top1:"<<top1<<endl;
	//cout<<"top2:"<<top2<<endl;
}
int pop()
{
	if(top>=0)
	{
		int x=array[top];
		top--;
		if(min_array[q]==x)
		{
			q--;
		}
		return x;
	}
	else{
	cout<<"stack underflow";
	exit(1);}
}
void print()
{
	cout<<"Stack1:";
	for(int i=0;i<=top;i++)
	{
		cout<<"\t"<<array[i];
	}
}
int main(int argc, char** argv) {
	push(8);
	push(2);
	push(3);
	push(1);
	print();
	cout<<endl;
	pop();
	minimum();
	//cout<<"the popped element from stack one:"<<pop()<<endl;
//	cout<<"the popped element from stack one:"<<pop()<<endl;
	//cout<<"min value in the stack is: "<<minimum()<<endl;
	return 0;
}
