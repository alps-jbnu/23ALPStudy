#include <stdio.h>

int main(void)
{
    int n, sum=0, min=99;

    for(int i=0; i<7; i++){
        scanf("%d", &n);
        if(n%2==1){
            sum+=n;
            if(min>n)
                min=n;
        }
    }

    if(sum==0) printf("-1");
    else printf("%d\n%d", sum, min);

    return 0;
}