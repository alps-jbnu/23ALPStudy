#include <stdio.h>

int main(){
    int A, B, C;
    int arr[10] = {0, };
    int num;
    scanf("%d %d %d", &A, &B, &C);

    int n = A * B * C;
    while(n > 0){
        num = n % 10;
        arr[num]++;
        n /= 10;
    }
    for(int i = 0; i < 10; i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}