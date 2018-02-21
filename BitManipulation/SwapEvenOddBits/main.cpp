#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*this code swaps the even and the odd bits in the number*/
int Swap(int x)
{
	int even_bits= x & 0xAA;
	int odd_bits=x & 0x55;
	even_bits=even_bits>>1;
	odd_bits=odd_bits<<1;
	return (even_bits|odd_bits);
}
int main(int argc, char** argv) {
	int x=23;
	printf("the number we get after swapping the even and odd bits of %d is: %d",x,Swap(x));
	return 0;
}
