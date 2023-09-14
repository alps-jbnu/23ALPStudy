#include <bits/stdc++.h>

using namespace std;

#define MAX_N 64

string quadTree[MAX_N+3];

void compression_recursion(int N, int r, int c){ // r(row), c(column)
    int value, sum = 0;
    queue<int> q;
    bool flag = false;  // check block's element are not same

    for (int i=r;i<r+N;i++){
        for (int j=c;j<c+N;j++){
            if (quadTree[r][c] != quadTree[i][j]){
                flag = true;
                break;
            }
        }
        if (flag) break;
    }

    if (!flag){
        cout << quadTree[r][c];
        return ;
    }

    cout << "(";
    for (int i=r;i<r+N;i+=N/2){
        for (int j=c;j<c+N;j+=N/2){
            compression_recursion(N/2, i, j);
        }
    }

    cout << ")";

    return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N;

    cin >> N;

    for (int i=0;i<N;i++){
        cin >> quadTree[i];
    }

    compression_recursion(N,0,0);
    
    return 0;
}
