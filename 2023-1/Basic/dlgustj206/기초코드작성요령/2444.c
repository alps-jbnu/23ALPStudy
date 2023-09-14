#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=n-i-1; j>0; j--) printf(" ");
        for(int k=2*i+1; k>0; k--) printf("*");
        printf("\n");
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<i+1; j++) printf(" ");
        for(int k=0; k<2*n-(2*i+1); k++) printf("*");
        printf("\n");
    }

    return 0;
}