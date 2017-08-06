// HW 08 part 1.b 

int function(int x,int y);
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv)

{
    
    printf("%d",function(4,3));
    return 0;
}

int function(int x,int y)
{
    if (x==0 | y==0)
        return 0;
    else        
        return (function(x-1,y)+function(x,y-1)+x+y);
    
    
    
}