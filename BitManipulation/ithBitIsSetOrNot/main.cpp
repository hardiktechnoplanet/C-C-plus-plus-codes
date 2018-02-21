#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*this code checks if the ith bit is set in the given number or not*/
bool SetOrNot(int x,int i)
{
	if((x & (1 << (i-1))))
	{
		printf("hello");
	return true;
}
	else
	printf("no hello");
	return false;
}
int main(int argc, char** argv) {
	int x=9;
	int i=4;
	if (SetOrNot(x,i)==true)
	printf("yes");
	else
	printf("no");
	return 0;
}
