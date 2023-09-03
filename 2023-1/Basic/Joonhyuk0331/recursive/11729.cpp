#include <stdio.h>
#include <math.h>

void Matb(int a,int b,int n)
{
    if(n==1){
        printf("%d %d\n",a,b);
        return ;
    }
    Matb(a,6-a-b,n-1);
    printf("%d %d\n",a,b);
    Matb(6-a-b,b,n-1);
}

int main()
{
    int n=0;
    scanf("%d",&n);
    int n2=pow(2,n)-1;
    printf("%d\n",n2);
    Matb(1,3,n);
}
