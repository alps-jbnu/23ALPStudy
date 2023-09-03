#include <bits/stdc++.h>

using namespace std;

#define MAX_N 14

int chessQueen_recursion(int N, int qx, int qy, int queens, int cases, bool cmpMapp[MAX_N+3][MAX_N+3]){

    if (N == 1) return cases+1;  // ...

    bool mapp[MAX_N+3][MAX_N+3];

    for (int i=qx+1;i<N;i++){
        for (int j=0;j<N;j++){
            mapp[i][j] = cmpMapp[i][j];
        }
    }

    for (int k=qx;k<N;k++){
        mapp[k][qy] = true;
    }

    int k = qx+1;
    int l = qy-1;
    while (k < N && l >= 0){
        mapp[k][l] = true;
        k++; l--;
    }

    k = qx+1; l = qy+1;
    while (k < N && l < N){
        mapp[k][l] = true;
        k++; l++;
    }

    for (int j=0;j<N;j++){
        if (mapp[qx+1][j]) continue;

        if (queens == N) return cases+1;

        cases = chessQueen_recursion(N,qx+1,j,queens+1,cases,mapp);
    }
    
    return cases;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N, cases=0;
    bool mapp[MAX_N+3][MAX_N+3] = {};

    cin >> N;

    for (int j=0;j<N;j++){
        cases = chessQueen_recursion(N,0,j,1,cases,mapp);
    }

    cout << cases;
    
    return 0;
}
