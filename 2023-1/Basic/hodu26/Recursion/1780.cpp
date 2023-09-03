#include <bits/stdc++.h>

using namespace std;

#define MAX_P 2187

int paper[MAX_P+3][MAX_P+3];

int cntPaper[3]; // -1, 0, 1

int checkPaper_recursion(int N, int r, int c){ // r(row), c(column)
    int stored, sum = 0;
    bool flag = false;  // check block's element are not same

    if (N == 1){
        cntPaper[paper[r][c]+1]++;
        return paper[r][c];
    }

    int cmp = paper[r][c];
    for (int i=r;i<r+N;i+=N/3){
        for (int j=c;j<c+N;j+=N/3){

            stored = checkPaper_recursion(N/3, i, j);
            if (cmp != stored || stored == 10) flag = true;
        }
    }

    if (!flag) cntPaper[cmp+1] -= 8;
    else return 10;

    return cmp;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N;

    cin >> N;

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> paper[i][j];
        }
    }

    checkPaper_recursion(N,0,0);

    cout << cntPaper[0] << '\n' << cntPaper[1] << '\n' << cntPaper[2];
    
    return 0;
}
