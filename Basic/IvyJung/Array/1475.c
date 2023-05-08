#include <stdio.h>

int main(){
    int arr[10] = {0};
    int n, num;
    scanf("%d", &n);

    while (n > 0){
        num = n % 10;
        arr[num]++;
        n /= 10;
    }
    arr[6] = (arr[6] + arr[9] + 1) / 2;

    int max = 0;
    for(int i = 0; i < 9; i++){
        if(max < arr[i]) max = arr[i];
    }
    printf("%d", max);

    return 0;
}
// Created by Ivy Jung on 2023/03/22.
//
