#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n,i=0,j=0,x=0,m=0;
    scanf("%d", &n);
    m=2*n-1;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if((i<n)&&(j<n))
            {
                x=i<j?i:j;
            }
            else if((i>=n)&&(j<n))
            {
                x=(j<(m-1-i))?j:(m-1-i);
            }
            else if((i>=n)&&(j>=n))
            {
                x=((m-1-j)<(m-1-i))?(m-1-j):(m-1-i);
            }
            else if((i<n)&&(j>=n))
            {
                x=((m-1-j)<i)?(m-1-j):i;
            }
            printf("%d ",n-x);
        }
        printf("\n");
    }
  	// Complete the code to print the pattern.
    return 0;
}

