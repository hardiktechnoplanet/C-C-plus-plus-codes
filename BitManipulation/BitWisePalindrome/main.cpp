#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*this code checks if the number is plaindrome or not*/
bool kthBitSet(int x, int q)
{
	return (x & (1 << (q-1)));
}
bool IsPalindrome(int x)
{
	int l=1;
	int r=sizeof(int);
	while(l<r)
	{
		if(kthBitSet(x,l)!=kthBitSet(x,r))
		return false;
		l++;r--;
	}
	return true;
}
int main(int argc, char** argv) {
	int x=8;
	if(IsPalindrome(x))
	printf("yes");
	else
	printf("no");
	return 0;
}
