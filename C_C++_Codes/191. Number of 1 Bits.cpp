#include <iostream>

using namespace std;

/*Instead of checking every bit of the number, we repeatedly flip the least-significant 1-bit
 of the number to 0, and add 1 to the sum. As soon as the number becomes 0, we know that it 
 does not have any more 1-bits, and we return the sum.
The key idea here is to realize that for any number n, doing a bit-wise AND of n and n - 1 
flips the least-significant 1-bit in n to 0. 

In the binary representation, the least significant 1-bit in n always corresponds to a 0-bit
in n - 1. Therefore, anding the two numbers n and n - 1 always flips the least significant 
1-bit in n to 0, and keeps all other bits the same.*/

int hammingWeight(uint32_t n)
{
	int sum=0;
	
	while(n)
	{
		sum++;
		n &=(n-1);
	}
	return sum;
}
int main()
{
	uint32_t n=50;
	cout<<hammingWeight(n);
}
