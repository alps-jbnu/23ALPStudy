#include <bits/stdc++.h>

using namespace std;

int T;
int table[15];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--){
        int N;
        cin >> N;
        table[1] = 1;
        table[2] = 2;
        table[3] = 4;
        for(int i = 4; i <= N; i++){
            table[i] = table[i-1] + table[i-2] + table[i-3];
        }
        cout << table[N] << '\n';
    }
}