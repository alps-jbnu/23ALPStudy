#include <bits/stdc++.h>

using namespace std;

#define MAX_N 2187

char draw[MAX_N+3][MAX_N+3];

void starDraw_recursion(int N, int r, int c){ // r(row), c(column)

    if (N == 3){
        for (int i=r;i<r+N;i+=N/3){
            for (int j=c;j<c+N;j+=N/3){
                if (i == r+N/3 && j == c+N/3) continue; 

                draw[i][j] = '*';
            }
        }
        return ;
    }

    for (int i=r;i<r+N;i+=N/3){
        for (int j=c;j<c+N;j+=N/3){
            if (i == r+N/3 && j == c+N/3) continue;

            starDraw_recursion(N/3, i, j);
        }
    }

    return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N;

    cin >> N;

    for (int i=0;i<N;i++){
        fill(draw[i], draw[i]+N, ' ');
    }

    starDraw_recursion(N,0,0);

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cout << draw[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}
