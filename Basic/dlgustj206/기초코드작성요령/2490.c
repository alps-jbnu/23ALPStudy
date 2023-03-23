#include <stdio.h>

int main(void)
{
    int n;

    for(int i=0; i<3; i++){
        int cnt=0;

        for(int j=0; j<4; j++){
            scanf("%d", &n);
            if(n==0)
                cnt++;
        }

        if(cnt==0)
            printf("E\n");
        else if(cnt==1)
            printf("A\n");
        else if(cnt==2)
            printf("B\n");
        else if(cnt==3)
            printf("C\n");
        else
            printf("D\n");
    }

    return 0;
}