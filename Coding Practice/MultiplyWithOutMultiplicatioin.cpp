#include<bits/stdc++.h>

/* function to multiply two numbers x and y*/
int multiply(int x, int y)
{
   int result;
   //Test Case I
   /* 0  multiplied with anything gives 0 */
   if(y == 0)
     return 0;
 
   /* Add x one by one */
   if(y > 0 )
     return (x + multiply(x, y-1));
  
  /* the case where y is negative */
   if(y < 0 )
     return -multiply(x, -y);
}
 
int main()
{
  printf("\n %d", multiply(5, -11));
  return 0;
}
