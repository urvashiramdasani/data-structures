#include<stdio.h>
int fun(int count) 
{ 
    printf("%d\n",count); 
    if(count<3) 
    { 
      fun(fun(fun(++count))); 
    } 
    return count; 
}
void main()
{
    int r=fun(1);
}