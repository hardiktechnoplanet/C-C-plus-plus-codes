#include <iostream>
#include <stdio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*this code counts the number of set bits in a given number*/
int NoOfSetBits(int n)
{
	int count=0;
	while(n)
	{
		cout<<"hello"<<endl;
		if((n&1)==1)
		count++;
		n=n>>1;
	}
	return count;
}
int main(int argc, char** argv) {
	int x=7;
	printf("the number of set bits in the given number %d is: %d",x,NoOfSetBits(x));
	return 0;
}
