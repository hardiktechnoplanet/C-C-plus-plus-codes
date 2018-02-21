#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int countSetBits(int n)
{
	int count=0;
	while(n)
	{
		count+=n&1;
		n=n>>1;
	}
	return count;
}
int FlippedCount(int a,int b)
{
	return countSetBits(a^b);
}
int main(int argc, char** argv) {
	int a=31;
	int b=14;
	printf("no of bits: %d",FlippedCount(a,b));
	return 0;
}
