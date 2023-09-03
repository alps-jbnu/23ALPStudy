#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char arr[7000][7000];//전역변수임(함수del_star에서 접근해야되므로)

void del_star(int size,int where_x,int where_y)//(where_x,where_y) 이라는 절대좌표에서 size*size에서만큼의 공백채움
{
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            arr[where_y+i][where_x+j]=' ';
        }
    }
}

void print_star(int size)
{
    for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int where_x,where_y,size;
    int N=0;
    scanf("%d",&N);
    
    for(int i=1;i<=N;i++){//N*N범위만큼 별로 채우기
        for(int j=1;j<=N;j++){
            arr[i][j]='*';
        }
    }
    
    for(int a=1;pow(3,a)<=N;a++){//포인팅
        for(int y=0;pow(3,a)*y+pow(3,a-1)+1<=N;y++){
            for(int x=0;pow(3,a)*x+pow(3,a-1)+1<=N;x++){
                
                where_x=pow(3,a)*x+pow(3,a-1)+1;
                where_y=pow(3,a)*y+pow(3,a-1)+1;
                size=pow(3,a)/3;
                del_star(size,where_x,where_y);
            }
        }
    }
    
    print_star(N);
    return 0;
}
