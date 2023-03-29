#include <stdio.h>

int main(void)
{
    int n, i, j;
    scanf("%d", &n);
    
    for(i=0; i<n; i++)
    {
        for(j=0; j<i+1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}