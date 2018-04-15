#include <stdio.h>
void swap(int *xp, int *yp)
{
    if (xp == yp) // Check if the two addresses are same
      return;
    *xp = *xp + *yp;
    *yp = *xp - *yp;
    *xp = *xp - *yp;
}
int main()
{
  int x = 10;
  int y= 20;
  swap(&x, &y);
  printf("After swap(&x, &y): x = %d  y=%d", x,y);
  return 0;
}
