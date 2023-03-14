#include <stdio.h>

int main()
{
    int i=0,j=0,max=0,x=0;
    int arr[9];
    while(i<9){
        scanf("%d",&arr[i]);
        i++;
    }
    max=arr[0];
    while(j<8){
        x++;
        if(max<arr[j+1]){
            max=arr[j+1];
            x=0;}
        j++;
    }
    printf("%d\n%d",max,9-x);
}
