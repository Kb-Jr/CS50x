#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n,m,y,born,death;
    
    // TODO: Prompt for start size
     do 
     {
        n=get_int ("start size: \n");   
     }
     while (n<9);
    // TODO: Prompt for end size
    do
    {
        m=get_int ("end size: \n");
    }
    while (m < n);
    
    // TODO: Calculate number of years until we reach threshold
    for(y=0; n < m; y++ )
   { 
    born = n/3;
    death = n/4;
    n = n + born - death;
   }
   
    // TODO: Print number of years
    {
        printf("Years: %i\n",y);
    }
    
}
  