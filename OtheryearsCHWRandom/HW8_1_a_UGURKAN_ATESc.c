/*main c file for calculating bit in 
 recursion code.
 HW 08 PART 1.1*/
#include <stdio.h>
#include <stdlib.h>
void bin(unsigned n);

int main(void)
{
    bin(12);
    printf("\n");
    bin(4);
}

void bin(unsigned n)
{
  
    if (n > 1)
        bin(n/2);
 
   
    printf("%d", n % 2);
}