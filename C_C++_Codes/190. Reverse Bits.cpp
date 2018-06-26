#include <iostream>
using namespace std;

/*Loop through all the bits of an integer. If a bit at ith 
position is set in the i/p no. then set the bit at (NO_OF_BITS – 1) – i 
in o/p. Where NO_OF_BITS is number of bits present in the given number.*/

uint32_t reverseBits(uint32_t n) {
        uint32_t size=sizeof(n)*8;
        uint32_t reverse_no=0;
        int i;
        for(i=0;i<size;i++)
        {
            if(n & (1<<i))
            {
                reverse_no |=(1<<((size-1)-i));
            }
        }
        return reverse_no;
        
    }
int main()
{
	uint32_t n=550;
	cout<<reverseBits(n);
}
