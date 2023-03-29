#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100004], D[100004];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    D[0] = 0;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
        D[i] = D[i-1] + A[i];
    }

    while(M--){
        int i, j;
        cin >> i >> j;
        cout << D[j] - D[i-1] << '\n';
    }
}