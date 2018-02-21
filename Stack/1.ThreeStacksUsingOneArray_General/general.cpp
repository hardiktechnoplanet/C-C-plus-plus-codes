#include <iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
#define stackSize 300
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int buffer[stackSize*3];
int stackPointer[]={0,0,0};

void push(int x,int stackNo)
{
	int index=stackSize*stackNo+stackPointer[stackNo]+1;
	stackPointer[stackNo]++;
	buffer[index]=x;
}
int pop(int stackNo)
{
	int index=stackSize*stackNo+stackPointer[stackNo];
	stackPointer[stackNo--];
	int value=buffer[index];
	return value;
	buffer[index]=0;
}

int main(int argc, char** argv) {
	push(10,1);
	push(20,1);
	push(80,2);
	push(75,0);
	push(800,2);
	push(8,0);
	cout<<endl;
	cout<<"the popped element from stack one:"<<pop(1)<<endl;
	cout<<"the popped element from stack one:"<<pop(2)<<endl;
	cout<<"the popped element from stack one:"<<pop(0)<<endl;
	return 0;
}
