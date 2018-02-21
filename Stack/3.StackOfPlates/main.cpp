#include <iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
# define stackSize 2
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int buffer[stackSize*3];
int stackPointer[]={0,0,0};
int stackNumber;
int index;
void push(int x)
{
	if(stackPointer[0]<stackSize)
	{
		cout<<"stack 0"<<endl;
		stackNumber=0;
	}
	else if((stackPointer[0]>=stackSize)&&(stackPointer[1]<stackSize))
	{
		cout<<"stack 1"<<endl;
		stackNumber=1;
	}
	else if((stackPointer[1]>=stackSize)&&(stackPointer[2]<stackSize)){
		cout<<"stack 2"<<endl;
	    stackNumber=2;
   }
   else
   {
   	cout<<"no space"<<endl;
   }
   //for debugging
   /*cout<<"0th: "<<stackPointer[0]<<endl;
   cout<<"1th: "<<stackPointer[1]<<endl;
   cout<<"2th: "<<stackPointer[2]<<endl;*/
	index=stackSize*stackNumber+stackPointer[stackNumber]+1;
	stackPointer[stackNumber]++;
	buffer[index]=x;
}
int pop()
{
	int x;
	x=buffer[index];
	index--;
	return x;
}
int main(int argc, char** argv) {
push(2);
push(3);
push(4);
push(5);
push(20);
//push(3);
/*push(4);
push(5);*/
cout<<"the popped element is: "<<pop()<<endl;
	
	return 0;
}
