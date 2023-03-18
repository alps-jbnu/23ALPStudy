#include <stdio.h>

int main(void)
{
    int n, i, j, k;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            printf(" ");

        }
        for (k = 0; k < i + 1; k++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}