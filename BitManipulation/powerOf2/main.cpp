#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*this code checks if the given number is power of 2 or not*/
bool Power(int x)
{
	return x && (!(x&(x-1)));
}
int main(int argc, char** argv) {
	int x=32;
	if(Power(x)==1)
	printf("yes");
	else
	printf("no");
	return 0;
}
