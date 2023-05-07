#include <bits/stdc++.h>
using namespace std;

string video[64];
int n;

void printRes(int num, int y, int x){
    char cur = video[y][x];

    for (int i = y; i < y + num; i++)
        for (int j = x; j < x + num; j++)
            if (video[i][j] != cur){
                cout << '(';
                printRes(num / 2, y, x);
                printRes(num / 2, y, x + num / 2);
                printRes(num / 2, y + num / 2, x);
                printRes(num / 2, y + num / 2, x + num / 2);
                cout << ')';
                return;
            }

    cout << cur;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> video[i];

    printRes(n, 0, 0);

    return 0;
}