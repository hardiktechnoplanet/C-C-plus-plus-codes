#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
unsigned int reverseBits(unsigned int x)
{
unsigned int reverse_no=0,i,temp;
unsigned int no_of_bits=sizeof(x);
for(i=0;i<no_of_bits;i++)
{
	temp= (x & (1 << i));
	if(temp)
	{
	reverse_no|=((1 << ((no_of_bits-1)-i)));
}
}
return reverse_no;
}
int main(int argc, char** argv) {
	unsigned int x=-2;
	printf("%u\n",x);
	printf("%u",reverseBits(x));
	return 0;
}
