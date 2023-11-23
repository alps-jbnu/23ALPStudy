#include <stdio.h>
#include <stdlib.h>

int pc[100][100];
int visited[100];
int virus;

void check_connect(int n, int k);
void check(int n, int k);

int main (void){
    int n, con;
    int x, y;
    
    scanf("%d", &n);
    scanf("%d", &con);
    for(int i=0; i<con; i++){
        scanf("%d %d", &x, &y);
        pc[x-1][y-1] = 1;
        pc[y-1][x-1] = 1;
        
    }
    visited[0] = 1;
    check_connect(n, 0);
    
    printf("%d\n", virus);
}

void check_connect(int n, int k){
    for(int i=0; i<n; i++){
        if(visited[i] == 0 && pc[k][i] == 1){
            visited[i] = 1;
            check_connect(n, i);
            virus ++;
            
        }
    }
}
