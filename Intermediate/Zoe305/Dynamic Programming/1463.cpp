#include <bits/stdc++.h>

using namespace std;

int table[1000001];
int N;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 2; i <= N; i++){
        table[i] = table[i-1]+1;
        if(i%2 == 0) table[i] = min(table[i], table[i/2]+1);
        if(i%3 == 0) table[i] = min(table[i], table[i/3]+1);
    }

    cout << table[N];
}