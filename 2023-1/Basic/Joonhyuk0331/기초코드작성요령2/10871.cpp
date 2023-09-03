#include <stdio.h>

int main()
{
    int n=0,x=0,i=0;
    scanf("%d %d",&n,&x);
    while(n>0){
        scanf("%d",&i);
        if(i<x)
            printf("%d ",i);
        n--;
    }
}
