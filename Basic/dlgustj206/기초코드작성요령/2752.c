#include <stdio.h>

int main(void)
{
    int a, b, c, temp;
    scanf("%d %d %d", &a, &b, &c);

    if(a>b){
        temp=a;
        a=b;
        b=temp;
    }
    if(b>c){
        temp=b;
        b=c; c=temp;
    }
    if(a>b){
        temp=a;
        a=b;
        b=temp;
    }

    printf("%d %d %d", a, b, c);
    
    return 0;
}